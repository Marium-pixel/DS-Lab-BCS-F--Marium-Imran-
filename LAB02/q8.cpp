
/* Task #8:
Create a dynamic program to store temperature readings of a city for n days and m different times in a day
using a 2D array.
=> Calculate the daily average temperature.
=> Find the hottest and coldest day
*/

#include <iostream>
 
using namespace std;

 

int main() { 
    int  days;
    int times;
    cout<<"how many days of temp reading do you want? \n";
    cin>>days;
    cout<<"how many times per day do you want a reading to be taken? \n";
    cin>>times;

    int **temperature=new int*[days];

    for(int i=0;i<days;i++){
        temperature[i]=new int[times];
    }

        cout<<"enter"<<days*times<<"readings\n";
    for(int i=0;i<days;i++){
        for(int j=0;j<times;j++){
            cin>> temperature[i][j];

        }
    }
 /*

bool tempH=false;
bool tempC=false;
*/
 float hottest=-9999;
float coldest=100000;
int hday=-1;
int cday=-1;
cout<<" mThe temperatures are:\n";
    for(int i=0;i<days;i++){
        
        for(int j=0;j<times;j++){
            cout<<temperature[i][j]<<" ";

        }
        cout<<endl;
    }

    float avg;
    for(int i=0;i<days;i++){
        int sum=0;
        for(int j=0;j<times;j++){
            if(temperature[i][j]>hottest){
                 hottest=temperature[i][j];
                 hday=i+1;
                  

            }

            if(temperature[i][j] < coldest){
                 coldest=temperature[i][j];
                 cday=i+1;
                

            }
             sum=sum + temperature[i][j];

        }

        avg=sum/times;
        cout<<"the average of this day was "<<avg<<endl;

         
    }

    cout<<"the hottest of the days was day "<<hday<<"at"<<hottest<<endl;
    cout<<"the coldest of the days was day "<<cday<<"at"<<coldest<<endl;

     

    
      

    for(int i=1;i<=days;i++){
    delete[] temperature[i];
}
delete[] temperature;

 
return 0;
        
    }
