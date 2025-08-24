/*Q1. Suppose you are developing a bank account management system, and you have defined the
BankAccount class with the required constructors. You need to demonstrate the use of these
constructors in various scenarios.
1. Default Constructor Usage: Create a default-initialized BankAccount object named
account1. Print out the balance of account1.
2. Parameterized Constructor Usage: Create a BankAccount object named account2 with
an initial balance of $1000. Print out the balance of account2.
3. Copy Constructor Usage: Using the account2 you created earlier, create a new
BankAccount object named account3 using the copy constructor. Deduct $200 from
account3 and print out its balance. Also, print out the balance of account2 to ensure it
hasn't been affected by the transaction involving account3.*/

#include<iostream>
using namespace std;

class BankAccount{
    private:
    int *account;
     
    public:
    BankAccount(){
        account=new int(5000);//default

    }

    BankAccount(int acc2){
        
        account=new int(acc2);//parametrized
    }

    int getaccount(){
        return *account;
    }

    BankAccount(const BankAccount& other){
        account = new int(*other.account);
    }

    void withdraw(int amount){
        *account-=amount; //dereferencing warna address araha hai 
    }
 //using withdraw function because operator overloading too long >:/


};

int main(){
    BankAccount account1;
    cout<<"account 1 has $"<<account1.getaccount()<<endl;
    BankAccount account2(1000);
    
    cout <<"account 2 has $" << account2.getaccount()<<endl;

    BankAccount account3=account2;
    account3.withdraw(200);
    cout<<"account 3 has $"<<account3.getaccount()<<endl;
    cout <<"account 2 has $" << account2.getaccount()<<endl;//works:D
}
