
#include <iostream>
 
using namespace std;



int main(){
    int n;
int arr[10];
  cout<<"enter values in this array\n";
  for(int i=0;i<10;i++){
    cin>>arr[i];

  }

  for(int i=0;i<10;i++){
    for(int j=0;j<9;j++){
        if(arr[j]>arr[j+1]){
            int temp;
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
  }

  for(int i=0;i<10;i++){
    cout<<arr[i]<<endl;;

  }

  return 0;
}
