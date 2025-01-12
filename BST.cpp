#include <iostream>
using namespace std;

// Node structure for the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Class for the BST
class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Function to insert a node into the BST
    Node* insert(Node* root, int data) {
        if (root == nullptr) {
            return new Node(data);
        }

        if (data < root->data) {
            root->left = insert(root->left, data);
        } else if (data > root->data) {
            root->right = insert(root->right, data);
        }

        return root;
    }

    // In-order traversal (Left -> Root -> Right)
    void inorder(Node* root) {
        if (root == nullptr) return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Pre-order traversal (Root -> Left -> Right)
    void preorder(Node* root) {
        if (root == nullptr) return;

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    // Post-order traversal (Left -> Right -> Root)
    void postorder(Node* root) {
        if (root == nullptr) return;

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

int main() {
    BST bst;
    
    // Inserting nodes into the BST
    bst.root = bst.insert(bst.root, 50);
    bst.insert(bst.root, 30);
    bst.insert(bst.root, 20);
    bst.insert(bst.root, 40);
    bst.insert(bst.root, 70);
    bst.insert(bst.root, 60);
    bst.insert(bst.root, 80);

    // Printing different tree traversals
    cout << "In-order Traversal: ";
    bst.inorder(bst.root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    bst.preorder(bst.root);
    cout << endl;

    cout << "Post-order Traversal: ";
    bst.postorder(bst.root);
    cout << endl;

    return 0;
}
