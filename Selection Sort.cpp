#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Função para realizar o Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> arr(10);

    // Lendo valores do usuário para preencher o vetor
    for (int i = 0; i < 10; ++i) {
        cout << "Digite o valor para a posicao " << i+1
         << ": ";
        cin >> arr[i];
    }

    // Medindo o tempo de execução do Selection Sort
    chrono::high_resolution_clock::time_point comeco = chrono::high_resolution_clock::now();

    selectionSort(arr);

    chrono::high_resolution_clock::time_point fim = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_ms = fim - comeco;

    // Exibindo o vetor resultante
    cout << "\nVetor ordenado: \n" << "{";
    for (int i = 0; i < 9; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[9] << "}\n";

    cout << "\nTempo de execucao do Selection Sort: " << fixed << setprecision(4) << elapsed_ms.count() << " milissegundos" << endl;


    return 0;
}
