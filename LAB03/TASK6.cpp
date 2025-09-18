/*Write a function to flatten the structure so that all nodes appear in a single-level list.
• Example:
• 1 → 2 → 3
• |
• 4 → 5
Output: 1 → 2 → 4 → 5 → 3
 */
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;
    Node(int val) {
        data = val;
        next = NULL;
        child = NULL;
    }
};

class MultiList {
public:
    Node* head;
    MultiList() {
        head = NULL;
    }

    void insertNext(Node* prev, int val) {
        Node* newnode = new Node(val);
        if (prev)
            prev->next = newnode;
        else
            head = newnode;
    }

    void insertChild(Node* parent, int val) {
        Node* newnode = new Node(val);
        if (parent)
            parent->child = newnode;
    }

    void flatten() {
        if (!head) return;
        Node* current = head;
        while (current) {
            if (current->child) {
                Node* childHead = current->child;
                Node* temp = childHead;
                while (temp->next) temp = temp->next;
                temp->next = current->next;
                current->next = childHead;
                current->child = NULL;
            }
            current = current->next;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    MultiList list;

    list.insertNext(NULL, 1);
    Node* n1 = list.head;
    list.insertNext(n1, 2);
    Node* n2 = n1->next;
    list.insertNext(n2, 3);

    list.insertChild(n2, 4);
    Node* n4 = n2->child;
    list.insertNext(n4, 5);

    cout << "Original list: ";
    list.display();

    list.flatten();

    cout << "Flattened list: ";
    list.display();

    return 0;
}
