#include <iostream>
using namespace std;

// Definition for a binary tree node
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        left = right = nullptr;
    }
};

// Insertion into a Binary Search Tree
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);  // Create and return new node if the tree is empty
    }
    // If key is less than root, insert in left subtree
    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    // If key is greater, insert in right subtree
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;  // Return unchanged root pointer
}

// Searching a value in a BST
Node* search(Node* root, int key) {
    if (root == nullptr || root->key == key) {
        return root;  // Return node if found or return nullptr if not found
    }
    // Key is smaller than root's key, search in the left subtree
    if (key < root->key) {
        return search(root->left, key);
    }
    // Key is larger, search in the right subtree
    return search(root->right, key);
}

// Find the minimum value node in a BST
Node* findMin(Node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Deletion in Binary Search Tree
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;  // Return if the tree is empty
    }

    // Traverse the tree to find the node to be deleted
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Node to be deleted found

        // Case 1: Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Node with two children, get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->key << " ";
    }
}

// Main function to demonstrate the BST
int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;

    cout << "\nAfter deleting 20\n";
    root = deleteNode(root, 20);
    inorderTraversal(root);
    cout << endl;

    cout << "\nAfter deleting 30\n";
    root = deleteNode(root, 30);
    inorderTraversal(root);
    cout << endl;

    cout << "\nAfter deleting 50\n";
    root = deleteNode(root, 50);
    inorderTraversal(root);
    cout << endl;

    return 0;
}
