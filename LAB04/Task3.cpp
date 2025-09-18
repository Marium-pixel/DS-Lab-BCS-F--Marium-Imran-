/*Implement the Selection Sort algorithm. The program should take an array of integers from
the user, find the smallest element, and exchange it with the element at the first position.
This process should continue until the array is completely sorted. Display the sorted array
to the user.
 */
#include <iostream>
using namespace std;

int main() {
    int n ;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout<<"unsorted array \n";
 for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
 }

  
for(int i=0;i < n-1;i++){
        int minindex=i;

 for (int j = i+1; j < n; j++) {
         
            if (arr[j] < arr[minindex]) {
                 minindex=j;
            }
        
    }

    int temp=arr[i];
    arr[i]=arr[minindex];
    arr[minindex]=temp;
}

 cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
