#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -left - 1;
}

int main() {
    int Employee[] = {1, 5, 10, 15, 20, 25, 30};
    int n = sizeof(Employee) / sizeof(Employee[0]);

    int target = 6;

    int pos = binarySearch(Employee, n, target);

    if (pos >= 0) {
        cout << "Employee ID " << target << " found at index: " << pos << endl;
    } else {
        int insertPos = -pos - 1;
        cout << "Employee ID " << target << " not found. Inserting at index: " << insertPos << endl;
        for (int i = n; i > insertPos; i--) {
            Employee[i] = Employee[i - 1];
        }
        Employee[insertPos] = target;
        n++;
        cout << "Updated Employee IDs: ";
        for (int i = 0; i < n; i++) {
            cout << Employee[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
