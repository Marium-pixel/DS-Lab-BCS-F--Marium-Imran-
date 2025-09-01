
/* :
Write a C++ program that dynamically creates a 2D matrix and provides:
=> Addition of two matrices.
=> Subtraction of two matrices.
=> Ensure safe memory handling with proper allocation/deallocation.
*/

#include <iostream>
 
using namespace std;

 

int main() { 
    int mrows=4,mcols=4;
    int nrows=4,ncols=4;
    int **matrice1=new int*[mrows];

    for(int i=0;i<mrows;i++){
        matrice1[i]=new int[mcols];
    }

        cout<<"enter 16 elements for the matrice 1\n";
    for(int i=0;i<mrows;i++){
        for(int j=0;j<mcols;j++){
            cin>>matrice1[i][j];

        }
    }

     int **matrice2=new int*[nrows];

    for(int i=0;i<nrows;i++){
        matrice2[i]=new int[ncols];
    }

        cout<<"enter 16 elements for the matrice 2\n";
    for(int i=0;i<nrows;i++){
        for(int j=0;j<ncols;j++){
            cin>>matrice2[i][j];

        }
    }

 
cout<<" matrice 1:\n";
    for(int i=0;i<mrows;i++){
        
        for(int j=0;j<mcols;j++){
            cout<<matrice1[i][j]<<" ";

        }
        cout<<endl;
    }

    cout<<" matrice 2:\n";
    for(int i=0;i<mrows;i++){
        
        for(int j=0;j<mcols;j++){
            cout<<matrice2[i][j]<<" ";

        }
        cout<<endl;
    }

    cout<<"addition \n";
 
    for(int i=0;i<4;i++){
        
        for(int j=0;j<4;j++){
            cout<<matrice1[i][j] + matrice2[i][j]<<" ";

        }
        cout<<endl;
    }

     cout<<"subtraction \n";
 
    for(int i=0;i<4;i++){
        
        for(int j=0;j<4;j++){
            cout<<matrice1[i][j] - matrice2[i][j]<<" ";

        }
        cout<<endl;
    }

    for(int i=1;i<=mrows;i++){
    delete [] matrice1[i];
}
delete [] matrice1;

for(int i=1;i<=nrows;i++){
    delete [] matrice2[i];
}
delete [] matrice2;

return 0;
        
    }
