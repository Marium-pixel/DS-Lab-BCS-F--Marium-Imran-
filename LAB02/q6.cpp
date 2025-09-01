/* Task #6:
Implement a Safe Pointer class to wrap around an integer pointer.
=> Provide methods for setValue(), getValue(), and release().
=>
Demonstrate the class by storing marks of 5 students and printing them safely without
direct pointer manipulation.


*/

#include <iostream>
using namespace std;

class SafePointer {
private:
    int* ptr;

public:
    SafePointer() {
        ptr = nullptr;
    }

    SafePointer(int value) {
        ptr = new int(value);
    }

    ~SafePointer() {
        delete ptr;
    }

    void setValue(int value) {
        if (ptr == nullptr) {
            ptr = new int(value);
        } else {
            *ptr = value;
        }
    }

    int getValue() const {
        if (ptr == nullptr) {
            cout << "Pointer not initialized!" << endl;
            return 0;
        }
        return *ptr;
    }

    void release() {
        delete ptr;
        ptr = nullptr;
    }
};

int main() {
    const int n = 5;
    SafePointer students[n];

    cout << "Enter marks of " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        int marks;
        cout << "Student " << i+1 << ": ";
        cin >> marks;
        students[i].setValue(marks);
    }

    cout << "\nMarks of students:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i+1 << ": " << students[i].getValue() << endl;
    }

    // release all manually (not necessary, destructor will handle it)
    for (int i = 0; i < n; i++) {
        students[i].release();
    }

    return 0;
}
