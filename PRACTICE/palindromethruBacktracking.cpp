
#include <iostream>
#include<string>
 using namespace std;
 const int N=5;

 char maze[N][N]={
        {'G','R','O','O','T'}, 
        {'B','A','R','R','O'}, 
        {'W','R','D','B','S'},
        {'R','A','D','A','R'},
        {'W','E','S','T','G'}
         


  
 };

 bool visited[N][N]= {false};
  
 
 bool isPalindrome(const string &s)
{
    int l=0;
    int r=s.size()-1;
    while(l<r){
        if(s[l]!=s[r])return false;
        l++;
        r--;
    }
    return true;

}  
void findPalindrome(int i,int j,string path){
    if(i<0 || j<0 || i>=N || j>=N){
         
        return ; //base for stopping
    }
    if(visited[i][j])return;

    path+=maze[i][j];
    visited[i][j]=true;
    
    if (path.size()>=3 && isPalindrome(path) )
    { 
        cout<<"Palisdrome:"<<path<<endl;
    }

    findPalindrome(i+1,j,path);
    
    findPalindrome(i-1,j,path);
    
    findPalindrome(i,j+1,path);
    
    findPalindrome(i,j-1,path);
    
     
    visited[i][j]=false;


 }


int main(){
     
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                 string path="";
                 findPalindrome(i,j,path);
                 
                    
                
            }
             
        }
 
  
  return 0;
}
