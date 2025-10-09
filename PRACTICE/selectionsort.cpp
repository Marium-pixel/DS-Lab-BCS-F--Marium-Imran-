
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

  for(int i=0;i<n-1;i++){   //runs from 1 till second last index
      int min=i;            //first i gets assigned min index
    for(int j=i+1;j<n;j++){  //second till last index
         if(arr[j]<arr[min]){      //if the value infront is smaller than minindex it gets swapped
            min=j;
         }
        }
         int temp=arr[i];  //swaping happens outside of immediate loop
         arr[i]=arr[min];//swap i w minindex
         arr[min]=temp;
    
  }

  for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;;

  }

  return 0;
}

