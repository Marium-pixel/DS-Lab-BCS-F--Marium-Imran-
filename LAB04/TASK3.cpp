/* 3. Reverse in Groups of K
Reverse nodes of a singly linked list in groups of size k.
• Example:
o Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8, with k = 3
o Output: 3 → 2 → 1 → 6 → 5 → 4 → 8 → 7
 */
 
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
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Insert at end
    void insert(int value) {
    Node* newnode = new Node(value);
        if (head == NULL) {
            head = newnode;
        } else {
            Node* temp = head;
     while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    //  reverse in groups of k
    Node* reverseKGroup(Node* head, int k) {
        if (head == NULL) return NULL;

        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;
        int count = 0;

        //  reverse normal
        while (current != NULL && count < k) {
    next = current->next;
   current->next = prev;
    prev = current;
    current = next;
            count++;
        }

        // Step 2: recurse for  the other values in list
          if (next != NULL) {
            head->next = reverseKGroup(next, k);
        }

         // connecting head w prev
    return prev;
    }
 
    void reverseInGroups(int k) {
        head = reverseKGroup(head, k);
    }

    // Display function
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    for (int i = 1; i <= 8; i++) {
        list.insert(i);
    }

    cout << "Og List: ";
    list.display();

    int k  ;
    cout<<"enter the number of reversla in groups you want\n";
    cin>>k;
    list.reverseInGroups(k);

    cout << "Reversing string in group" << k ;
    list.display();

    return 0;
}
