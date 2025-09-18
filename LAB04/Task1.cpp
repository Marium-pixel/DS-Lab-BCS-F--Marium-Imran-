/*Implement a linear search algorithm to find a specific integer in an array. The program
should take an array of integers and a target value as input from the user. Print the index of
the target value if it's found or a message indicating that the element is not in the array.
 */
#include <iostream>
using namespace std;

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter target: ";
    cin >> target;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << "Target found at index " << i << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Target not found" << endl;
    return 0;
}
