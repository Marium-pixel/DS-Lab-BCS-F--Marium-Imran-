// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


int main() {
     int courses;
     cout<<"enter the number of courses";
     int students;
     cout<<" \nenter the number of students total";
     cin>>students;
     int **std=new int*[students];
     int numcourse[students];
     
     for (int i=0;i<students;i++){
         cout<<"enter the total number of courses taken by student"<<i+1<<endl;
         cin>>numcourse[i];
         std[i]=new int[numcourse[i]];


     }
     
    
     



return 0;
}
