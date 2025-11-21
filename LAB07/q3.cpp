/* Task-3:
Suppose you are working for a company that organizes a marathon every year. There are 10
participants in the marathon, and their finish times are recorded in seconds.
Write a program in C++ that uses Merge sort to find the top 5 fastest runners. Create an array of
runner objects that will store the participant&#39;s name and finish time in seconds.
 Prompt the user to input the participant&#39;s names and finish times into the array.
 Implement a merge function that will merge two subarrays of runners based on their finish
time in ascending order.
 Use the Merge sort algorithm to sort the runners based on their finish time by calling the
merge function in step 3.
 Display the top 5 fastest runners to the console, along with their name and finish time in
seconds.
 Use the appropriate data types and size for the arrays and variables to ensure efficient
memory usage.

Steps of Merge Sort:
 Divide: Split the array into two halves until each sub-array contains a single element.

 Conquer (Sort): Recursively sort each half.
 Merge: Merge the two sorted halves into a single sorted array.
 */

#include <iostream>
#include <string>
using namespace std;

class Runner {
public:
    string name;
    int time;      
};
 
void merge(Runner arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;

    // Temp  arrays
    Runner* L = new Runner[n1];
    Runner* R = new Runner[n2];
 
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
 
    while (i < n1 && j < n2) {
        if (L[i].time <= R[j].time) { 
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    } 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}
 
void mergeSort(Runner arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);           
        mergeSort(arr, mid + 1, right);   
        merge(arr, left, mid, right);       
    }
}

int main() {
    Runner runners[10];

    cout << "Enter names and finish times (in seconds) of 10 participants:\n";

    for (int i = 0; i < 10; i++) {
        cout << "\nParticipant " << i + 1 << " Name: ";
        cin >> runners[i].name;

        cout << "Finish Time (seconds): ";
        cin >> runners[i].time;
    } 
    mergeSort(runners, 0, 9);

    cout << "\n\nTop 5 Fastest Runners:\n";
    cout << "-----------------------------------\n";

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << runners[i].name 
             << " - " << runners[i].time << " seconds\n";
    }

    return 0;
}
