#include <iostream>
using namespace std;

int main() {
    int months;
    cout << "Enter number of months to track expenses: ";
    cin >> months;

    double* expenses = new double[months];

    for (int i = 0; i < months; i++) {
        cout << "Enter expense for month " << i + 1 << ": ";
        cin >> expenses[i];
    }

    char choice;
    cout << "\nDo you want to add more months? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int extra;
        cout << "Enter additional months: ";
        cin >> extra;

        double* newExpenses = new double[months + extra];

        for (int i = 0; i < months; i++) {
            newExpenses[i] = expenses[i];
        }

        delete[] expenses;
        expenses = newExpenses;

        for (int i = months; i < months + extra; i++) {
            cout << "Enter expense for month " << i + 1 << ": ";
            cin >> expenses[i];
        }

        months += extra;
    }

    double total = 0;
    for (int i = 0; i < months; i++) {
        total += expenses[i];
    }
    double average = total / months;

    cout << "\nTotal expenses: " << total << endl;
    cout << "Average expenses: " << average << endl;

    delete[] expenses;

    return 0;
}
