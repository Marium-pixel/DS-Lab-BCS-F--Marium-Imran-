
#include <iostream>
 
using namespace std;



int main(){
    int n;
    cout<<"enter the numebr of elemnts in array\n";
    cin>>n;
int arr[n];
  cout<<"enter values in this array\n";
  for(int i=0;i<n;i++){
    cin>>arr[i];

  }

  for(int i=1;i<n;i++){    
      int key=arr[i]; //key is the first elemnt
      int j=i-1;            //j is before i
     while(j>=0 && arr[j]>key){    //loop of shifting starts from condition j=0 and j > that key and 0
        arr[j+1]=arr[j];        //shift j fwd
        j--;                      //move j back
     }

     arr[j+1]=key;            //move the key fwd to be compared w j
          
    
  }

  for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;;

  }

  return 0;
}
