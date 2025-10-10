//merges 2 sorted lists siply by connectin tail of first list to the head of the second
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
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

Node* mergeLists(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* temp = head1;
    while (temp->next)
        temp = temp->next;
    temp->next = head2;

    return head1;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    insert(list1, 1);
    insert(list1, 2);
    insert(list1, 3);

    insert(list2, 4);
    insert(list2, 5);
    insert(list2, 6);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    Node* merged = mergeLists(list1, list2);
    cout << "Merged List: ";
    printList(merged);

    return 0;
}
