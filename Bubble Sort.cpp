#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Função para realizar o Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main() {
    vector<int> arr(10);

    // Lendo valores do usuário para preencher o vetor
    for (int i = 0; i < 10; ++i) {
        cout << "Digite o valor para a posicao " << i+1 << ": ";
        cin >> arr[i];
    }

    // Medindo o tempo de execução do Bubble Sort
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    bubbleSort(arr);

    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_ms = end - start;

    cout << "\nTempo de execucao do Bubble Sort: " << fixed << setprecision(4) << elapsed_ms.count() << " milissegundos." << endl;

    // Exibindo o vetor resultante
    cout << "\nVetor ordenado: \n" << "{";
    for (int i = 0; i < 9; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[9] << "}\n";

    return 0;
}
