#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Merge two sorted linked lists into one sorted list
Node* mergeSortedLists(Node* head1, Node* head2) {
    // Base cases
    if (!head1) return head2;
    if (!head2) return head1;

    Node* mergedHead = NULL;
    Node* mergedTail = NULL;

    // Choose initial head (smallest of the two)
    if (head1->data < head2->data) {
        mergedHead = mergedTail = head1;
        head1 = head1->next;
    } else {
        mergedHead = mergedTail = head2;
        head2 = head2->next;
    }

    // Merge the rest
    while (head1 && head2) {
        if (head1->data < head2->data) {
            mergedTail->next = head1;
            head1 = head1->next;
        } else {
            mergedTail->next = head2;
            head2 = head2->next;
        }
        mergedTail = mergedTail->next;
    }

    // Attach any remaining nodes
    if (head1) mergedTail->next = head1;
    if (head2) mergedTail->next = head2;

    return mergedHead;
}

// Helper to display a list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    // Create List 1: 1,3,5,7
    insert(list1, 1);
    insert(list1, 3);
    insert(list1, 5);
    insert(list1, 7);

    // Create List 2: 2,4,6,8
    insert(list2, 2);
    insert(list2, 4);
    insert(list2, 6);
    insert(list2, 8);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    Node* merged = mergeSortedLists(list1, list2);
    cout << "\nMerged Sorted List: ";
    printList(merged);

    return 0;
}
