#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[20], R[20];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr1[10] = {5, 8, 12, 3, 7, 19, 2, 15, 9, 11};
    int arr2[10] = {4, 6, 20, 1, 13, 18, 10, 17, 14, 16};

    int combined[20];
    for (int i = 0; i < 10; i++) combined[i] = arr1[i];
    for (int i = 0; i < 10; i++) combined[10 + i] = arr2[i];

    mergeSort(combined, 0, 19);

    cout << "Sorted using Merge Sort:\n";
    for (int i = 0; i < 20; i++) cout << combined[i] << " ";
}
