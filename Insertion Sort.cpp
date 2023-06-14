#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Função para realizar o Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr(10);

    // Lendo valores do usuário para preencher o vetor
    for (int i = 0; i < 10; ++i) {
        cout << "Digite o valor para a posicao " << i+1 << ": ";
        cin >> arr[i];
    }

    // Medindo o tempo de execução do Insertion Sort
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    insertionSort(arr);

    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_ms = end - start;

    cout << "\nTempo de execucao do Insertion Sort: " << fixed << setprecision(4) << elapsed_ms.count() << " milissegundos" << endl;

    // Exibindo o vetor resultante
    cout << "\nVetor ordenado: \n" << "{";
    for (int i = 0; i < 9; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[9] << "}\n";

    return 0;
}
