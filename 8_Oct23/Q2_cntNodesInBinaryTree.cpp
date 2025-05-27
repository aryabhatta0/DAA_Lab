#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

Node* createBinaryTree(int n, vector<int>& arr) {
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int ind = 1;
    while(ind < n && !q.empty()) {
        auto curr = q.front(); q.pop();
        if(ind < n && arr[ind] != -1) {
            curr->left = new Node(arr[ind]);
            q.push(curr->left);
        }
        ind++;

        if(ind < n && arr[ind] != -1) {
            curr->right = new Node(arr[ind]);
            q.push(curr->right);
        }
        ind++;
    }

    return root;
}

int countNodes(Node* root) {
    queue<Node*> q;
    q.push(root);

    int cnt = 0;
    while(!q.empty()) {
        auto curr = q.front(); q.pop();
        cnt++;
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }

    return cnt;
}

void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    Node* root = createBinaryTree(n, arr);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\n";

    int totalNodes = countNodes(root);
    cout << "Total Nodes: " << totalNodes << "\n";
    return 0;
}
