#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int interpolationSearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (arr[high] == arr[low]) {
            if (arr[low] == target) return low;
            else return -1;
        }

        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == target)
            return pos;
        if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

bool isUniform(vector<int>& arr) {
    if (arr.size() < 2) return true;
    int diff = arr[1] - arr[0];
    for (int i = 2; i < arr.size(); i++) {
        if (arr[i] - arr[i - 1] != diff)
            return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter number of account balances: ";
    cin >> n;

    vector<int> balances(n);
    cout << "Enter account balances: ";
    for (int i = 0; i < n; i++) {
        cin >> balances[i];
    }

    sort(balances.begin(), balances.end());

    cout << "Sorted balances: ";
    for (int x : balances) cout << x << " ";
    cout << endl;

    if (!isUniform(balances)) {
        cout << "Error: Data is not uniformly distributed." << endl;
        return 0;
    }

    int target;
    cout << "Enter balance to search: ";
    cin >> target;

    int result = interpolationSearch(balances, target);

    if (result != -1)
        cout << "Balance " << target << " found at index: " << result << endl;
    else
        cout << "Balance " << target << " not found." << endl;

    return 0;
}
