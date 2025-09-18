/*   2. Merge Two Sorted Singly Linked Lists
Implement a function to merge two sorted singly linked lists into one sorted list.   • Example:
o List A: 1 → 3 → 5
o List B: 2 → 4 → 6
o Output: 1 → 2 → 3 → 4 → 5 → 6
• Bonus: Solve without creating new nodes (rearrange pointers) */

//note: this code depends on the lists being sorted in ascending order
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

//  logic : starts a dummy node to combine the 2 lists,compares both values of the 
// lists and takes the smaller one
Node* mergeSorted(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    // Dummy node to start the merged list
    Node dummy(0);
    Node* tail = &dummy;

    while (head1 && head2) {
        if (head1->data < head2->data) { //takes smaller
            tail->next = head1;  //takes 1 as the first integer of merged list
            head1 = head1->next;  //move ptr fwd to 3
        } else {
            tail->next = head2; //compare 2 & 3 now
            head2 = head2->next; //move ptr fwd
        }
        tail = tail->next;
    }

    // Attach remaining part
    if (head1) tail->next = head1;
    else tail->next = head2;

    return dummy.next; //  ask sir about merging of head
}

int main() {
    LinkedList list1, list2;
 
    list1.insertAtEnd(1);
    list1.insertAtEnd(3);
    list1.insertAtEnd(5);
 
    list2.insertAtEnd(2);
    list2.insertAtEnd(4);
    list2.insertAtEnd(6);

    cout << "List 1: ";
    list1.display();
    cout << "List 2: ";
    list2.display();

    Node* mergedHead = mergeSorted(list1.head, list2.head);

    cout << "Merged List: ";
    Node* temp = mergedHead;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
