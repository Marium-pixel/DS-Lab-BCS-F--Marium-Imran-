#include <iostream>
using namespace std;


int main() {
    int rows,cols;
    int choice;
    cout<<"enter the number of rows \n";
    cin>>rows;
    cout<<"enter the number of columns \n";
    cin>>cols;

    int **arr=new int*[rows];
    for(int i=1;i<=rows;i++){
        arr[i]=new int[cols];
    }
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=cols;j++){
            arr[i][j]=0;
        }
    }
   cout<<"fil the seats with 1 if occupied,0 if not \n";
   for(int i=1;i<=rows;i++){
    for(int j=1;j<=cols;j++){
        cin>>arr[i][j];
    }
   }
cout<<"matrix of seats: \n";
for(int i=1;i<=rows;i++){
    for(int j=1;j<=cols;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
for(int i=1;i<=rows;i++){
    delete [] arr[i];
}
delete [] arr;
 
return 0;
}
