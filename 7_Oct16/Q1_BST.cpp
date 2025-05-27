#include <iostream>
using namespace std;

// Define the structure of a node in the BST
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if(root == NULL) {
        return new Node(val);
    }

    /**
    if(val < root->key)
        root->left = insert(root->left, val);
    else if(val > root->key)
        root->right = insert(root->right, val);
    */

    Node* curr = root;
    while(curr != NULL) {
        if(val < curr->key) {
            if(curr->left) curr = curr->left;
            else {
                curr->left = new Node(val);
                break;
            }
        } else if(val > curr->key) {
            if(curr->right) curr = curr->right;
            else {
                curr->right = new Node(val);
                break;
            }
        }
        // we assume two val can't be same in a BST
        else break;
    }

    return root;
}

void printBST(Node* root) {
    if(root == NULL) return;

    printBST(root->left);
    cout << root->key << " ";
    printBST(root->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);

    cout << "BST in sorted order: ";
    printBST(root);
    cout << endl;

    return 0;
}
