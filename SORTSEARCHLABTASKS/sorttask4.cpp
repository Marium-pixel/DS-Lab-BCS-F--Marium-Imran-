#include <iostream>
using namespace std;

int main() {
    int desks[8] = {1, 4, 2, 1, 3, 5, 2, 6}; 
    int n = 8;

    cout << "Initial arrangement: ";
    for (int i = 0; i < n; i++) {
        cout << desks[i] << " ";
    }
    cout << endl;

    for (int i = 1; i < n; i++) {
        int key = desks[i];
        int j = i - 1;

        while (j >= 0 && desks[j] < key) {
            desks[j + 1] = desks[j];
            j--;
        }
        desks[j + 1] = key;

        cout << "After pass " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << desks[k] << " ";
        }
        cout << endl;
    }

    cout << "Final sorted arrangement: ";
    for (int i = 0; i < n; i++) {
        cout << desks[i] << " ";
    }
    cout << endl;

    return 0;
}
