#include <iostream>
using namespace std;

class Heap {
private:
    int* arr;
    int capacity;
    int size;

    int parent(int i) { return (i - 1) / 2; }

    void heapify_up(int index) {
        while (index != 0 && arr[index] > arr[parent(index)]) {
            swap(arr[index], arr[parent(index)]);
            index = parent(index);
        }
    }

    void heapify_down(int index, int n) {
        int largest = index;
        int l = 2 * index + 1;
        int r = 2 * index + 2;

        if (l < n && arr[l] > arr[largest])
            largest = l;
        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapify_down(largest, n);
        }
    }

public:
    Heap(int cap = 100) {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    ~Heap() {
        delete[] arr;
    }

    void insertInMaxHeap(int value) {
        if (size == capacity) {
            cout << "Heap Overflow\n";
            return;
        }
        arr[size] = value;
        heapify_up(size);
        size++;
    }

    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int getSize() { 
        return size; 
    }
    int* getArray() {
         return arr; 
        }

    bool isMaxHeap() {
        for (int i = 0; i <= (size - 2) / 2; i++) {
            int l = 2*i+1;
            int r = 2*i+2;
            if (l < size && arr[i] < arr[l]) return false;
            if (r < size && arr[i] < arr[r]) return false;
        }
        return true;
    }

    void heapSort() {
        int n = size;
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify_down(i, n);

        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapify_down(0, i); 
        }
    }
};

int main() {
    Heap h;

    h.insertInMaxHeap(8);
    h.insertInMaxHeap(7);
    h.insertInMaxHeap(6);
    h.insertInMaxHeap(5);
    h.insertInMaxHeap(4);

    cout << "Max Heap: ";
    h.printHeap();

    if (h.isMaxHeap())
        cout << "Array is a Max Heap." << endl;
    else
        cout << "array is not a Max Heap." << endl;

    h.heapSort();
    cout << "array sorted in ascending order: ";
    h.printHeap();

    return 0;
}
