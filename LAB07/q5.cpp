/* Task-5:Implement Quick Sort using linked list in C++. Define a node for a linked list with integer data
and a pointer to the next node. Write a function to swap two nodes in the linked list. Write a
function to partition the linked list using the last node as the pivot. Implement the Quick Sort
algorithm using the partition function and the swap function. Finally, write a function to print the
sorted linked list. Your implementation should be able to handle empty linked lists and linked lists
with only one node. Test your implementation with a sample linked list containing the following
integers: 10, 7, 8, 9, 1, 5, 3. The expected output after sorting should be: 1 3 5 7 8 9 10.
 */
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* getTail(Node* cur) {
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == NULL)
                *newHead = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    *newEnd = tail;
    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end)
        return head;

    Node *newHead = NULL, *newEnd = NULL;

    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = NULL;

        newHead = quickSortRecur(newHead, temp);

        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

void quickSort(Node** headRef) {
    *headRef = quickSortRecur(*headRef, getTail(*headRef));
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

void push(Node** headRef, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

int main() {
    Node* head = NULL;
    int arr[] = {10, 7, 8, 9, 1, 5, 3};

    for (int i = 0; i < 7; i++)
        push(&head, arr[i]);

    quickSort(&head);

    cout << "Sorted Linked List:\n";
    printList(head);
}

