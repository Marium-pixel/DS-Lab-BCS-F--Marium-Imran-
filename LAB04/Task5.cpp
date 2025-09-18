/*Implement the Interpolation Search algorithm. The program should take a sorted array
with uniformly distributed values and a target value from the user. The algorithm should
estimate the position of the target and check if the estimated position holds the correct
value. If the element is found, print its index; otherwise, indicate that it's not present.
 */
#include <iostream>
using namespace std;

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements (sorted & uniformly distributed): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter target: ";
    cin >> target;

    int low = 0, high = n - 1;
    bool found = false;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) {
                cout << "Target found at index " << low << endl;
                found = true;
            }
            break;
        }

        // Estimate position
        int pos = low + ((double)(target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == target) {
            cout << "Target found at index " << pos << endl;
            found = true;
            break;
        }

        if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }

    if (!found) cout << "Target not found" << endl;

    return 0;
}
