
/* :
Task #10:
Design a program that maintains library book records using dynamic arrays.
=> Each row represents a category (e.g., Fiction, Science, History).
=> Each category has a different number of books (use a jagged array).
=> Store book IDs dynamically and allow the user to search for a given book ID.
=> Print whether the book is available and in which category.*/

#include <iostream>
 
using namespace std;

 

int main() { 
    int category;
    cout<<"enter the total number of categories";
    cin>>category;
    int**library=new int*[category];
    int books[category];

    for(int i=0;i<category;i++){
        cout<<"enter the total number of books in category"<<i+1<<endl;
        cin>>books[i];
        library[i]= new int[books[i]];

    }

    for(int i=0;i<category;i++){ 
        for(int j=0;j<books[i];j++){
            library[i][j]=1001+i;//take search number when running as 1000 + integer less than category number
        }
    }

     
    int bookid;
    cout<<"\n enter the id of the book you want to search";
    cin>>bookid;
bool found = false;
int foundCategory = -1;
    for(int i=0;i<category;i++){
         
        
        for(int j=0;j<books[i];j++){
            
            if(library[i][j]==bookid){ 
                found=true;
                foundCategory=i;
                break;
            }
             
            
        }
         if(found){
            break;
         }
            
        }

        if(found){
    cout << "\nBook available in category " << foundCategory+1 << endl;
} else {
    cout << "\nBook unavailable" << endl;
}
return 0;
        
    }
