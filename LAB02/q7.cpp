
/*Task #7:
A company has multiple departments, each department has a different number of employees.
=> Use a jagged array where each row corresponds to a department and columns store employee
salaries.
 Calculate:
 -> The highest salary in each department.
 -> The department with the overall maximum average salary.*/

#include <iostream>
 
using namespace std;

 

int main() { 
    int num_dept;
    cout<<"enter the total number of departments in the company";
    cin>>num_dept;
    int**dept=new int*[num_dept];
    int employees[num_dept];

    for(int i=0;i<num_dept;i++){
        cout<<"enter the total number of employee present in department"<<i+1<<endl;
        cin>>employees[i];
        dept[i]= new int[employees[i]];

    }

    for(int i=0;i<num_dept;i++){
        cout<<"enter the salaries for department"<<i+1<<endl;
        for(int j=0;j<employees[i];j++){
            cout<<"enter the salary of employee"<<j+1<<endl;
            cin>>dept[i][j];
        }
    }

    
    float max_avg=0;
    int max_dept=-1;

    for(int i=0;i<num_dept;i++){
        int sum=0;
        int highest=0;
        
        for(int j=0;j<employees[i];j++){
            sum=sum+dept[i][j];

            if(dept[i][j]>highest){
                highest=dept[i][j];
            }
            
        }
         float avg=sum/employees[i];
        if(avg>max_avg){
            max_avg=avg;
            max_dept=i+1;
            
        }

        cout<<"The highest salary of department"<<i+1<<"is:"<<highest;
    }


    cout<<"\n this is the department "<<max_dept<<" with the overall maximum average salary of :"<<max_avg<<endl;

    
    return 0;
}
