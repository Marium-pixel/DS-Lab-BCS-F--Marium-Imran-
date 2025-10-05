/* Binary search through recursion
 */
#include <iostream>
 
using namespace std;

int binsearch(int* arr,int target,int start,int end ) { //ptr before arr imp
    if(start<=end){
        int mid = start + (end - start)/2;
        if (arr[mid] == target){
            return mid;
        }
        else if(target > arr[mid]) {
            return binsearch( arr, target, mid +1,end);
        }

        else if(target < arr[mid]){
            return binsearch(arr,target,start,mid-1);
        }
    }

    else {
        return -1; //base case
    }
    
}

 
int main() {

    int array[]={2,3,5,6,7,9,10,11,34};
     
    int target=68;
    int start=0;
    int end=8;

    int result= binsearch(array,target,start,end);
     if (result != -1)
        cout << "Found at index " << result +1 << endl;
    else
        cout << "Not found" << endl;
    return 0;
}
