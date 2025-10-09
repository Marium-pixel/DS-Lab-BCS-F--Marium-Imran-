
#include <iostream>
 
using namespace std;

void shellsort(int myarr[],int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int j=gap;j<n;j++){
            int temp=myarr[j];
            int res=j;
            while(res>=gap && myarr[res-gap] > temp){
                myarr[res]=myarr[res-gap];
                res-=gap;
            }
            myarr[res]=temp;
        }
    }
}


int main(){
 
     int n;
     cout<<"enter the number of elemnts\n";
     cin>>n;
    
     int myarr[n]; 
  cout<<"enter values in this array\n";
  for(int i=0;i<n;i++){
    cin>>myarr[i];

  } 
  shellsort(myarr,n);

  for(int i=0;i<n;i++){
    cout<<myarr[i]<<endl;;

  }

  return 0;
}

