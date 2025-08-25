q.2/*Q2. Create a C++ class named "Exam" using DMA designed to manage student exam records,
complete with a shallow copy implementation? Define attributes such as student name, exam
date, and score within the class, and include methods to set these attributes and display exam
details. As part of this exercise, intentionally omit the implementation of the copy constructor  and copy assignment operator. Afterward, create an instance of the "Exam" class, generate a
shallow copy, and observe any resulting issues?*/

#include<iostream>
#include<cstring>
using namespace std;

class Exam {
private:
    char* name;
    char* examdate;
    int* score;

public: 
    Exam(const char* n, const char* edate, int s) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        examdate = new char[strlen(edate) + 1];
        strcpy(examdate, edate);

        score = new int(s);
    }

    // Destructor
    ~Exam() {
        delete[] name;
        delete[] examdate;
        delete score;
    }

    void display() {
        cout << "Name: " << name << "\n";
        cout << "Exam Date: " << examdate << "\n";
        cout << "Score: " << *score << "\n";
    }
};

int main() {
    Exam e1("Ali", "25,jan,2025", 90);

    cout << "Original object:\n";
    e1.display();

    // Shallow copy  
    Exam e2 = e1;

    cout << "\nShallow copied object:\n";
    e2.display();

    // When program ends, both destructors will try to free the same memory → crash / undefined behavior
    //program has these simple and easy to solve methods but also crash alot because of runtime errors due to bad dma assigmnets
}
