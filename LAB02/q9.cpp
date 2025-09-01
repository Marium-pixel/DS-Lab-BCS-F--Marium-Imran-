
/* TaTask #9:
Implement a program to represent a sparse matrix using a dynamic 2D array.
=> Input matrix elements.
=> Display the matrix in normal form.
=> Display the matrix in compressed form (row, column, value).

*/

#include <iostream>
 
using namespace std;

 

int main() { 
    int rows,cols ; 
    cout<<"enter the number of rows   in your matrix\n";
    cin>>rows;
    cout<<"enter the number of  columns in your matrix\n";
    cin>> cols;

    int **matrice1=new int*[rows];

    for(int i=0;i<rows;i++){
        matrice1[i]=new int[cols];
    }

        cout<<"enter"<<rows*cols<<" elements for the matrice 1\n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>matrice1[i][j];

        }
    }

     

 
cout<<" matrice 1:\n";
    for(int i=0;i<rows;i++){
        
        for(int j=0;j<cols;j++){
            cout<<matrice1[i][j]<<" ";

        }
        cout<<endl;
    }

    cout<<"row     column   value \n";
    
    for(int i=0;i<rows;i++){
        
        for(int j=0;j<cols;j++){
            if(matrice1[i][j]!=0){
                cout<<i+1<<"   "<<j+1<<"   "<<matrice1[i][j]<<endl;
            }
             

        }
        cout<<endl;
    }
for (int i=1;i<=rows;i++){
    delete[] matrice1[i];
    
    }

    
    delete[] matrice1;
    return 0;
}
