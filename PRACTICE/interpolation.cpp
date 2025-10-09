
#include <iostream>
 using namespace std;

int interpolation(int myarr[],int n,int x){
    int l=0;
    int h=n-1;
    while(l<=h && x>=myarr[l] && x<=myarr[h]){
        if(l==h){
            if(myarr[l]==x){
                   return l;
                   return -1;
            }
        }
        int pos = l + ((x - myarr[l]) * (h - l)) / (myarr[h] - myarr[l]);

 
        if(myarr[pos]==x){

        return pos;
        return -1;
        }
        if(myarr[pos]<x){
            l=pos+1;
           
        }

        if(myarr[pos]>x){
             h=pos-1;
        }
    }
    return -1;
    
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
 
  int x;
   cout<<"enter the target value\n";
  cin>>x;
  cout<< "value found at:"<<interpolation(myarr,n,x);
  


   

  return 0;
}

