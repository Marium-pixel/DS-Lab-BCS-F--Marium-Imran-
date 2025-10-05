#include<iostream>
using namespace std;
 
int mainArr[4][4]=
{    1,0,1,0,
     1,1,0,0,
     0,1,1,1,
     0,0,0,1   //main maze
       
};

int path [4][4]{
    0,0,0,0,
    0,0,0,0,     //control maze for tracking the values moved
    0,0,0,0,
    0,0,0,0
};

int solveratmaze(int i,int j,int n){

    if(i==n-1 && j==n-1){
        path[i][j]=1;
        return 1; //base case for reaching the end of the maze
    }
        if(i < n && j < n && i>=0 && j>=0 && mainArr[i][j] == 1 && path[i][j] == 0){
            path[i][j] = 1; 
              //marking it in the path if you need to back track to it
           if( solveratmaze(i+1,j,n) == 1){ //down
            return 1;
           }
           if( solveratmaze(i-1,j,n) == 1){ //up
            return 1;
           }
           if( solveratmaze(i,j+1,n) == 1){ //right
            return 1;
           }
           if( solveratmaze(i,j-1,n) == 1){ //left
            return 1;
           }
           path[i][j]=0; //unmarking it 
           


        }


    

    return 0;
}

int main(){

    solveratmaze(0,0,4);

    for(int i=0;i<4;i++){

        for(int j=0;j<4;j++){
            if(path[i][j]){
                cout<<i<<" "<<j<<"->"<<endl;//prints the position of i,j taken at each step to reach the end!
            }
        }
    }
     
     return 0;
}
