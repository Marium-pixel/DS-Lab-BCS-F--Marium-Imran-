/* 4. Josephus Problem using Circular Linked List
Use a circular linked list to solve the Josephus problem:
• N people stand in a circle, eliminating every k-th person until only one survives.
• Input: N = 7, k = 3
• Output: Position of survivor.
• Hint: Use circular traversal and deletion.
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

class CircLL {    
public:
    Node* head;

    CircLL() {
        head = NULL;
    }

    // circular linked list with N people
    void ListofN(int N) {    
        Node* prev = NULL;
        for (int i = 1; i <= N; i++) {
            Node* newNode = new Node(i);
        if (head == NULL) {
            head = newNode;
        } else {
        prev->next = newNode;
            }
            prev = newNode;
        }
        // THIS MakeS it circular
        prev->next = head;
    }

    // Josephus problem solution
    int getJPOSITION(int k) {    
        Node* current = head;
        Node* prev = NULL;

        while (current->next != current) { // more than 1 node remains check 
            // move k-1 steps
            for (int count = 1; count < k; count++) {
                prev = current;
                current = current->next;
            }
            // eliminating the k node check
            cout << "Eliminating position num:" << current->data << endl;
            prev->next = current->next;
            delete current;
            current = prev->next;
        }
        return current->data; // survivor
    }
};

int main() {
    int N  , k  ;


    cout<<"Eenter number of total ppl in list\n";
    cin>>N;
    cout<<"enter number of elimination \n";
    cin>>k;
    CircLL cll;
    cll.ListofN(N);

    int survivor = cll.getJPOSITION(k);

    cout << "The survivor is at position: " << survivor << endl;

    return 0;
}
