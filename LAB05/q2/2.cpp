/*   Next, demonstrate indirect recursion by creating two functions, functionA(int n)
and functionB(int n). functionA should call functionB, and functionB
should call functionA, forming a cycle that prints numbers in a specific pattern.
Ensure both programs have a base condition to prevent infinite loops.
 */

 
#include <iostream>
using namespace std;


int FunctionB(int n);
int FunctionA(int n){
        
        if(n<=0){
            return 0;
        }
        cout<<n<<" ";
        return FunctionB(n-1);
    }
    
    int FunctionB(int n){
        
        if(n<=0){
            return 0;
        }
        cout<<n<<" ";
        return FunctionA(n-1);
    }


int main() {
    int num;
    cout<<"enter a number "<<endl;
    cin>>num;
    
    cout << "Pattern of numbers: ";
    FunctionA(num);
    cout << endl;

    return 0;
}
