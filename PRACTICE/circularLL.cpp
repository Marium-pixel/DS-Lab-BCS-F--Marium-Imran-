#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    int data;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LL {
    Node* head;

public:
    LL() {
        head = NULL;
    }

    void InsertAtEnd(int data) {
        Node* newnode = new Node(data);
        if (head == NULL) {
            head = newnode;
            newnode->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }

    void InsertAtBeg(int data) {
        Node* newnode = new Node(data);
        if (head == NULL) {
            head = newnode;
            newnode->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }

    void deletenode(int data) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        // Case 1: Deleting the head node
        if (head->data == data) {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }

            // Only one node
            if (head->next == head) {
                delete head;
                head = NULL;
                return;
            }

            last->next = head->next;
            Node* del = head;
            head = head->next;
            delete del;
            cout << "Deleted head node " << data << "\n";
            return;
        }

        // Case 2: Deleting any other node
        do {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != data);

        if (temp == head) {
            cout << "Value not found\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Deleted node " << data << "\n";
    }

    void Display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << "back to head\n";
    }
};

int main() {
    LL l1;
    l1.InsertAtBeg(4);
    l1.InsertAtEnd(5);
    l1.InsertAtEnd(6);
    l1.InsertAtEnd(7);
    l1.InsertAtEnd(8);
    l1.InsertAtEnd(9);
    l1.Display();

    l1.deletenode(6);
    l1.Display();

    l1.deletenode(4);  // delete head
    l1.Display();

    l1.deletenode(9);  // delete tail
    l1.Display();
}
