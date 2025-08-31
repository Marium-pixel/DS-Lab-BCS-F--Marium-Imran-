   // Online C++ compiler to run C++ program online
   /*Design a program to handle marks of students in different courses using a jagged array
(since each student is enrolled in a different number of courses).
=> Input the number of courses each student takes.
=> Dynamically allocate memory for each student accordingly.
=> Calculate and display each student’s average marks.
*/
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

     for(int i=0;i<students;i++){
        cout<<"enter the marks for"<<numcourse[i]<<"courses \n";
        for(int j=0;j<numcourse[i];j++){
            cout<<"enter marks of student for course number"<<j+1<<endl;
            cin>>std[i][j];

        }
     }
     int sum;
     float avg;


     for(int i=0;i<students;i++){
        for(int j=0;j<numcourse[i];j++){
            sum+=numcourse[j];

        }
        avg=sum/numcourse[i];
        cout<<"avegrage of student"<<i+1<<"is:"<<avg<<endl;
         }
    
      for(int i=0;i<students;i++){
        delete[] std[i];
    }

    delete[] std;



return 0;
}
