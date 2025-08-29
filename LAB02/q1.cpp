 
#include <iostream>
using namespace std;


int main() {
int n;
 int choice;
cout<<"enter how many elements you want in array\n";
cin>>n;

int *arr=new int[n];


for(int i=1;i<=n;i++){
    arr[i]=0;
}

do
{

   
    
int index;
 
cout<<"enter the index of the array you want to chnage";
cin>>index;
if(index>n){
    cout<<"wrong make it less than"<<n<<endl;
}
cout<<"enter the value";
cin>>arr[index];
cout<<"array: \n";
for(int i=1;i<=n;i++){
    cout<<arr[i] ;
}
    cout<<"\nenter 1 if you want to keep updating ";
    cin>>choice;

}

 while (choice == 1);

delete[]  arr;
    return 0;
}
