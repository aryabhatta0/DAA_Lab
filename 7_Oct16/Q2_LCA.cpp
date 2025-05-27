#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        left = right = NULL;
    }
};

// Iterative insert function
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

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
        } else break;   // Duplicate key, not allowed in BST
    }

    return root;
}

void printBST(Node* root) {
    if(root == NULL) return;

    printBST(root->left);
    cout << root->key << " ";
    printBST(root->right);
}

Node* LCA(Node* root, int p, int q) {
    if(p > q) swap(p, q);

    if(p <= root->key && q >= root->key) return root;
    if(p < root->key && q <= root->key) return LCA(root->left, p, q);
    return LCA(root->right, p, q);
}

int main() {
    Node* root = NULL;
    // vector<int> arr {6, 2, 8, 0, 4, 7, 9, null, null, 3, 5};
    vector<int> arr {6, 2, 8, 0, 4, 7, 9, 3, 5};
    for(auto it: arr) {
        root = insert(root, it);
    }

    cout << "Inorder BST: "; printBST(root); cout << '\n';

    int p = 6, q = 8;
    Node* lca = LCA(root, p, q);
    cout << "LCA: " << lca->key << '\n';
}
