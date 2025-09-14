/*  1. Palindrome Check in Singly Linked List
Write a program to check if a singly linked list is a palindrome.
• Input: A singly linked list of integers.
• Output: true if the list reads the same forward and backward, false otherwise. */


#include <iostream>
using namespace std;

class Node {
public:    
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
    ~Node() {
        cout << "Node deleted with value of:" << data << endl;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    LinkedList() {
        head = NULL;
    }

    void insertBEG(int value) {
        Node* newnode = new Node(value);
        newnode->next = head;
        head = newnode;
    }

    // inserting at end
    void insert(int value) {
        Node* newnode = new Node(value);
        if (head == NULL) {   //  used == instead of =
            head = newnode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    string normaltraverse(){
        Node* temp = head;
        string s=" ";
        while (temp != NULL) {   //   was while(temp->next!=NULL), last node not displayed
            s+=to_string(temp->data);
            temp = temp->next;
        }
        return s;
    }

    void reverse(){
        if(head==NULL){
            cout<<"list is empty";

        }

        Node *next=NULL;
        Node *current=head;
        Node *prev=NULL;
         tail=head;
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;

        }

        head=prev;
    }

    void deleteval(int value) {
        // for head having the deleted val
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // searching for all other values:
        Node* current = head;
        Node* prev = NULL;
        while (current != NULL && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {   // <-- FIX: used == instead of =
            cout << "value not found\n";
            return;              // <-- FIX: need return after not found
        }

        prev->next = current->next;
        delete current;
    }

    // display all
    void display() {
        Node* temp = head;
        while (temp != NULL) {   // <-- FIX: was while(temp->next!=NULL), last node not displayed
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        cout << "LinkedList destroyed successfully.\n";
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(2);
    list.insert(1);
    list.display();
/*list.insertBEG(1);
    list.display();

    list.deleteval(88);
    list.display();
    */
    string forward = list.normaltraverse();
    list.reverse();
    list.display();
    string backward = list.normaltraverse();

if (forward == backward) {
    cout << "true (Palindrome)" << endl;
} else {
    cout << "false (Not Palindrome)" << endl;
}

    return 0;
}

 
