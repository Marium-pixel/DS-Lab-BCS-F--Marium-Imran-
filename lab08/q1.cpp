#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
 
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}
 
bool search(Node* root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find minimum value in subtree
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}
 
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        // Node found

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: One child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children → replace with inorder successor
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}
 
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
 
int main() {
    Node* root = NULL;
    int choice, value;

    while (true) {
        cout << "\n===== BINARY SEARCH TREE MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            cout << "Inserted!\n";
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            cout << "Deleted!\n";
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            if (search(root, value))
                cout << "Value found!\n";
            else
                cout << "Value NOT found!\n";
            break;

        case 4:
            cout << "Inorder (sorted): ";
            inorder(root);
            cout << endl;
            break;

        case 5:
            cout << "Preorder: ";
            preorder(root);
            cout << endl;
            break;

        case 6:
            cout << "Postorder: ";
            postorder(root);
            cout << endl;
            break;

        case 7:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
