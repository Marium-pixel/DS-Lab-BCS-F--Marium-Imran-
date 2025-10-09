/*  ratina maze,print the output as the way found out of the maze given, can only go where S and R
 blocks are but going to R block subtracts health points, also CANNOT go where X is as that is danger area. output: the maze with the
 path taken, and also the indexes of the path taken and also the health score with presumably was 0 at the start  */

#include <iostream>
 using namespace std;
 const int N=6;

 char maze[N][N]={
        'H','S','S','X','R','R',
        'S','S','S','X','S','R',
        'S','R','S','S','S','S',
        'S','X','S','X','S','S',
        'S','S','S','R','S','X',
        'S','X','S','S','S','D'


  
 };

 int path[N][N]= {0};
 int health=0;
  
bool solvemaze(int i,int j){
    if(i<0 || j<0 || i>=N || j>=N){
         
        return false; //base for stopping
    }
       
    if( maze[i][j]=='D'){
        path[i][j]=1;
        return true;
    }

    if(maze[i][j]=='X' || path[i][j]==1){
        return false;
    }

    path[i][j]=1;

    if(maze[i][j]=='R'){
        health--;
    }

    if(solvemaze(i+1,j)||solvemaze(i-1,j)||solvemaze(i,j+1)||solvemaze(i,j-1)){
        return true;
    }
     

    path[i][j]=0   ;    //backtrack
    if(maze[i][j]=='R'){
        health++;
    }
     
     return false;


 }


int main(){
    //start by finding the start pos H
    int start_i=-1;
    int start_j=-1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(maze[i][j]=='H'){
                start_i=i;
                start_j=j;
                break;
            }
        }
    }
    if(solvemaze(start_i,start_j)){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(path[i][j]==1){
                    cout<<"*";
                }
                else
                    cout<<maze[i][j]<<" ";
                
            }
            cout<<endl;
        }

        cout<<"Path coordinates:\n";

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(path[i][j]){
                    cout<<i<<" "<<j<<"->"<<endl;
                }
            }
        }


     cout<<"health:"<<health<<endl;
    }
    else{
    cout<<"no path found\n";
    }
  return 0;
}

