
## 💻 DAA Lab - 23/10/2024

## 📌 **Q1. Minimum Spanning Tree (MST)**

### **Problem Statement**:
Given a weighted, undirected, and connected graph of **V** vertices and **E** edges, the task is to find the **sum of weights of the edges** of the Minimum Spanning Tree (MST). 
Also, find the **edges involved** in formation of the MST.

### **Expected Complexity**

* **Time:** `O(E log V)`
* **Space:** `O(V)`

### ✅ **Example**

```
Input:
V = 5  
Edges = {
    (0, 1, 2), 
    (0, 3, 6), 
    (1, 2, 3), 
    (1, 3, 8), 
    (1, 4, 5), 
    (4, 2, 7)
}

Output:
MST Weight Sum = 16  
MST Edges = {
    (0, 1), (0, 3), (1, 2), (1, 4)
}
```



## 📌 Q2. Count Nodes in a Nearly Complete Binary Tree

### **Problem Statement**

Given the **level order traversal** of a **nearly complete binary tree**, construct the tree and return the **total number of nodes**.

> A nearly complete binary tree is a binary tree in which all levels are completely filled except possibly the last, and the last level has all keys as left as possible.

### **Expected Complexity**

* **Time:** `O(log² N)`
* **Space:** `O(H)` where `H` is the height of the tree

### ✅ **Example**

```
Input: [1, 2, 3, 4, 5, 6]

Constructed Tree:
       1
     /   \
    2     3
   / \   /
  4   5 6

Output: 6
```

---

## 📌 Q3. Longest Palindromic Subsequence

### **Problem Statement**

Given a string `s`, find the **length of the longest palindromic subsequence** in `s`.

> A **subsequence** is a sequence derived by deleting zero or more characters without changing the order of the remaining characters. A **palindromic** subsequence reads the same forward and backward.

### **Expected Complexity**

* **Time:** `O(N²)`
* **Space:** `O(N²)` (if using DP table)

### ✅ **Example**

```
Input: "bbbab"

Output: 4

Explanation: One possible longest palindromic subsequence is "bbbb".
```