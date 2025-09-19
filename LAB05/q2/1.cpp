/* 1. Write a simple C++ program that demonstrates direct recursion. Create a function
printNumbers(int n) that prints numbers from n down to 1 by calling itself
directly */

#include <iostream>
using namespace std;

int printNumbers(int n){
        
        if(n<=0){
            return 0;
        }
        cout<<n<<" ";
        return printNumbers(n-1);
    }

int main() {
    int num;
    cout<<"enter a number "<<endl;
    cin>>num;
    
    cout<< printNumbers(num);

    return 0;
}
