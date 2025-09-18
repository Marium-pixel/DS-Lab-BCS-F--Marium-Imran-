/*5.    Convert Between Linked List Types
Implement functions for conversion:
1. Convert a singly linked list into a doubly linked list.
2. Convert a singly linked list into a circular linked list.
• Demonstrate both conversions with sample input lists.
 */
#include <iostream>
using namespace std;

// Node for singly linked list
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Node for doubly linked list
class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    } 
    void insert(int value) {
        Node* newnode = new Node(value);
        if (!head) {
     head = newnode;
    return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newnode;
    }
 
    void displaySingly() {
     Node* temp = head;
 while (temp) {
            cout << temp->data << " -> ";
     temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // og to circ
    Node* makeCircular() {
        if (!head) return NULL;

        //  new copy of nodes for new list so data usage is valid
     Node* cHead = new Node(head->data);
    Node* tempOrig = head->next;
    Node* tempNew = cHead;

        while (tempOrig) {
            Node* newNode = new Node(tempOrig->data);
        tempNew->next = newNode;
        tempNew = newNode;
            tempOrig = tempOrig->next;
        }
        tempNew->next = cHead; // make circular by connecting tail to head
        return cHead;
    }

    // Display circular list (given head and length)
    void displayCircular(Node* cHead, int n) {
   Node* temp = cHead;
    for (int i = 0; i < n; i++) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "(head)" << endl;
    }

    //  og to doubly
    DNode* makeDoubly() {
        if (!head) return NULL;

    DNode* dHead = new DNode(head->data);
    Node* tempOrig = head->next;
    DNode* dTemp = dHead;

        while (tempOrig) {
        DNode* newNode = new DNode(tempOrig->data);
        dTemp->next = newNode;
            newNode->prev = dTemp;
        dTemp = newNode;
        tempOrig = tempOrig->next;
        }
        return dHead;
    }

    // Display doubly linked list
    void displayDoubly(DNode* dHead) {
        DNode* temp = dHead;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    int values[] = {10, 20, 30, 40, 50, 60, 70};
    for (int val : values) list.insert(val);

cout << "Original Singly Linked List: ";
list.displaySingly();
 
Node* cHead = list.makeCircular();
cout << "Circular Singly Linked List: ";
    list.displayCircular(cHead, 7);
 
DNode* dHead = list.makeDoubly();
    cout << "Doubly Linked List: ";
    list.displayDoubly(dHead);

    return 0;
}
