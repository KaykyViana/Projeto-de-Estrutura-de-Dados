#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Função para realizar o Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr(10);

    // Lendo valores do usuário para preencher o vetor
    for (int i = 0; i < 10; ++i) {
        cout << "Digite o valor para a posicao " << i+1 << ": ";
        cin >> arr[i];
    }

    // Medindo o tempo de execução do Quick Sort
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    quickSort(arr, 0, arr.size() - 1);

    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_ms = end - start;

    cout << "\nTempo de execucao do Quick Sort: " << fixed << setprecision(4) << elapsed_ms.count() << " milissegundos" << endl;

    // Exibindo o vetor resultante
    cout << "\nVetor ordenado: \n" << "{";
    for (int i = 0; i < 9; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[9] << "}\n";

    return 0;
}
