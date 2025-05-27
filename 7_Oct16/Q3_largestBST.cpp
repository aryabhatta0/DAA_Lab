#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int size;
    int max1; // max val in subtree rooted at Node
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        size = 1;
        max1 = val;
        left = NULL; right = NULL;
    }
};

void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->key << " (" << root->size << ") ";
    inorder(root->right);
}

// Level order construction
/**
Node* createBinaryTree(vector<int>& arr) {
    int n = arr.size();
    vector<Node*> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = (arr[i] == -1 ? NULL : new Node(arr[i]));
    }

    // 2*i + 2 <= n - 1
    for (int i = 0; i < n; i++) {
        Node* curr = nodes[i];
        if (2 * i + 1 < n)
            curr->left = nodes[2 * i + 1];
        if (2 * i + 2 < n)
            curr->right = nodes[2 * i + 2];
        nodes[i] = curr;
    }

    return nodes[0];
}
*/

// createBinaryTree using queue
Node* createBinaryTree(vector<int>& arr) {
    int n = arr.size();
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);

    int ind = 1;
    while (ind < n && !q.empty()) {
        auto curr = q.front(); q.pop();
        if (arr[ind] != -1) {
            curr->left = new Node(arr[ind]);
            q.push(curr->left);
        }
        ind++;

        if (arr[ind] != -1) {
            curr->right = new Node(arr[ind]);
            q.push(curr->right);
        }
        ind++;
    }

    return root;
}

int largestBST = 0;

bool dfs(Node* root) {
    if (!root) return true;
    bool flag = true;
    int sz = 1;
    int maxi = root->key;

    if (root->left) {
        if (!dfs(root->left) || root->key <= root->left->max1) flag = false;
        maxi = max(maxi, root->left->max1);
        sz += root->left->size;
    }

    if (root->right) {
        if (!dfs(root->right) || root->key >= root->right->max1) flag = false;
        maxi = max(maxi, root->right->max1);
        sz += root->right->size;
    }

    root->max1 = maxi;
    root->size = sz;

    if (flag) largestBST = max(largestBST, sz);
    return flag;
}

int main() {
    Node* root = NULL;
    // vector<int> arr = {1, 4, 4, 6, 8, -1, -1};
    // vector<int> arr = {6, 6, 2, -1, 2, 1, 3};
    vector<int> arr = {6, 2, 8, 0, 4, 7, 9, 3, 5};
    root = createBinaryTree(arr);

    dfs(root);

    cout << "Inorder Traversal with Sizes: ";
    inorder(root);
    cout << "\n";

    cout << "Size of Largest BST Subtree: " << largestBST << '\n';
    return 0;
}
