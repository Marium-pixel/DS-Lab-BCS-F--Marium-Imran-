#include <iostream>
using namespace std;

// Tail Recursion: sumTail calculates the sum using an accumulator (total)
int sumTail(int n, int total = 0) {
    if (n == 0) {
        return total;  // Base case: when n reaches 0, return the accumulated total
    }
    return sumTail(n - 1, total + n);  // Tail recursive call with updated total
}

// Non-Tail Recursion: sumNonTail calculates the sum by adding after the recursive call
int sumNonTail(int n) {
    if (n == 0) {
        return 0;  // Base case: when n reaches 0, the sum is 0
    }
    return n + sumNonTail(n - 1);  // Recursive call and then addition after return
}

int main() {
    int number;
    cout << "Enter a number to calculate the sum from 1 to n: ";
    cin >> number;

    // Tail recursion test
    cout << "Sum using tail recursion: " << sumTail(number) << endl;

    // Non-tail recursion test
    cout << "Sum using non-tail recursion: " << sumNonTail(number) << endl;

    return 0;
}
