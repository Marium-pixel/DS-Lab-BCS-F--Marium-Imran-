/*Q3. Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the
Rule of Three by defining a destructor, copy constructor, and copy assignment operator.
Demonstrate the behavior of both shallow and deep copy using test cases.*/

/*in order to explain the behaviours of shallow & deep
 I'll be using simulation1 & simulation 2.
 for simulation 1, 
32 to 39comment out lines
for simulation 2 you will need lines of code 32-39*/

#include<iostream>
using namespace std;

class Box{
    private:
    int *x;
    public:

    Box(){
        x=new int(0);//default constc

    }

    Box(int val){
        x=new int(val);
    }

    Box(const Box& other){
        x=new int(*other.x);//copy constc
    }

    Box& operator =(const Box& other){//comment out for sim2
        if(this != &other){
            delete x;
            x= new int(*other.x);
        }
        return *this;

    } //


    ~Box(){
        delete x;
    }

    int getx(){
        return *x;

    }

    void setx(int val) {
    *x = val;
}

 
};

int main(){
    Box a(70);
    cout<<"a is:"<<a.getx()<<endl;
    Box b;
    b=a;
    cout<<"b is:"<<b.getx()<<endl; 
    a.setx(100);
    cout<<"a is:"<<a.getx()<<endl;
    cout<<"b is:"<<b.getx()<<endl;
    
    /*EXPLANATION SIM 1:
    after a is assigned a different value of 100, b also gives 100 because it is simply copying the value again 
    because it is a shallow copy
    we do not want b to copy the value again only the memory and create a separate 'obj' than a ; a deep copy
    also when program ends a & b will delete the same memeory and cause a runtime error
    */

    /*EXPLANATION SIM 2:
    after a is assigned 100 that is a different value than the one b copied previously,
    70, b does not agian print 100 because it has CREATED  acompletely DIFFERENT MEMORY SPACE for itself
    and now does not REFLECT the copy of a again, instead it is like its own different object that has copied the 
    same space. also no program crash or runtime error now

    */



}
