//searching task 1
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int int_arr[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> int_arr[i];
    }

    int target;
    cout << "Enter target value: ";
    cin >> target;

    bool found = false;

    for (int i = 0; i < n; i++) {
        if (int_arr[i] == target) {
            cout << "Found at: " << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << target << " value not found" << endl;
    }

    return 0;
}
