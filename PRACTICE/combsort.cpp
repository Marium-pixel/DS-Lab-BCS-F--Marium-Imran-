
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
   float shrink=1.3;
   int gap=n; 
   bool swapped=true;
  while(gap>1){    
       gap=int(gap/shrink);
       if(gap<1){
        gap=1;
       }

       swapped=false;
       for(int i=0;i+gap<n;i++){

         if(arr[i]>arr[i+gap]){
            int temp=arr[i];
            arr[i]=arr[i+gap];
            arr[i+gap]=temp;
            swapped=true;
         }
       }
       
    
  }

  for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;;

  }

  return 0;
}

