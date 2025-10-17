#include<iostream>
using namespace std;

class Stack{
    int top;

    private:
    int a[MAX];
    Stack(){
        top=-1;
    }

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    
};

 bool Stack::push(int x){
    if(top >= (MAX-1)){
          COUT<<"Stack Overflow";
          return false;
    }

    else{
        a[top++]=x;
        cout<<x<<"pushed into stack\n";
        return true;
 }

 int Stack::pop(){
    if(top<0){
        cout<<"Stack Underflow\n";
        return 0;
    }
    else{
        int x=a[top--];
     
        return x;
    }
 }

 int Stack::peek(){
    if(top<0){
        cout<<"Stack Empty\n";
        return 0;
    }
    else{
        int x=a[top];
     
        return x;
    }
 }

 bool Stack::isEmpty(){
    return (top<0)
 }

int main(){
    cout<<"hello world";
}
