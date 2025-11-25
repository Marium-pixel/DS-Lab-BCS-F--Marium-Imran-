#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Insert into BST
Node* insertBST(Node* root, int val) {
    if (root == NULL) return new Node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

// Store inorder traversal
void inorder(Node* root, vector<int>& arr) {
    if (root == NULL) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

// Function to find median
float findMedian(Node* root) {
    if (root == NULL) return 0;

    vector<int> arr;
    inorder(root, arr);  // gets sorted values

    int n = arr.size();

    if (n % 2 != 0) {
        // odd size → median = element at (n+1)/2
        return arr[n/2];  // because index starts at 0
    }
    else {
        // even size → median = (n/2 + (n/2 + 1)) / 2
        int first = arr[(n/2) - 1];  // n/2-th element
        int second = arr[n/2];       // (n/2 + 1)-th element
        return (first + second) / 2.0;
    }
}

int main() {
    Node* root = NULL;

    // Example BST
    int values[] = {20, 10, 5, 15, 30, 25, 35};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        root = insertBST(root, values[i]);

    cout << "Median = " << findMedian(root) << endl;

    return 0;
}
