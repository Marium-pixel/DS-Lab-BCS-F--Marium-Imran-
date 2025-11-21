/* Task 6:

You have been given two unsorted arrays, arr1 and arr2, each containing 10 integers. You need to
combine the two arrays into a single sorted array using either Radix Sort or Merge Sort.
 Write a C++ program to combine arr1 and arr2 using Radix Sort and print the sorted array.
 Write a C++ program to combine arr1 and arr2 using Merge Sort and print the sorted array.
 */
#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int output[20];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() {
    int arr1[10] = {5, 800, 12, 3, 7, 119, 2, 15, 93, 11};
    int arr2[10] = {46, 6, 20, 1, 13, 138, 10, 17, 14, 16};

    int combined[20];
    for (int i = 0; i < 10; i++) combined[i] = arr1[i];
    for (int i = 0; i < 10; i++) combined[10 + i] = arr2[i];

    radixSort(combined, 20);

    cout << "Sorted using Radix Sort:\n";
    for (int i = 0; i < 20; i++) cout << combined[i] << " ";
}
