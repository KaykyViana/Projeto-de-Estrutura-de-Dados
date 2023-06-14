#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Função para realizar o Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    for (int i = 0; i < n1; ++i)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArray[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr(10);

    // Lendo valores do usuário para preencher o vetor
    for (int i = 0; i < 10; ++i) {
        cout << "Digite o valor para a posicao " << i+1 << ": ";
        cin >> arr[i];
    }

    // Medindo o tempo de execução do Merge Sort
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    mergeSort(arr, 0, arr.size() - 1);

    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_ms = end - start;

    cout << "\nTempo de execucao do Merge Sort: " << fixed << setprecision(4) << elapsed_ms.count() << " milissegundos" << endl;

    // Exibindo o vetor resultante
    cout << "\nVetor ordenado: \n" << "{";
    for (int i = 0; i < 9; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[9] << "}\n";

    return 0;
}
