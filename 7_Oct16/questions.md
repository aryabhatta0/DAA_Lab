## 💻 DAA Lab (16/10/2024)

### 📌 **Q1. Construct a BST, Implement Insert, and Print in Sorted Order**

**Task:**

* Build a Binary Search Tree by inserting nodes.
* Implement an insert function.
* Perform an **in-order traversal** to print the BST in sorted order.

---

### 📌 **Q2. Lowest Common Ancestor (LCA) in a BST**

**Problem Statement:**
Given a Binary Search Tree and two nodes `p` and `q`, find their **Lowest Common Ancestor (LCA)**.
According to [Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor):

> “The lowest common ancestor is the lowest node in the tree that has both `p` and `q` as descendants (including a node being a descendant of itself).”

**Constraints:**

* Both `p` and `q` are guaranteed to exist in the BST.
* `p ≠ q`

#### ✅ Example:

```
        6
      /   \
     2     8
    / \   / \
   0   4 7   9
      / \
     3   5
```

**Input:** `p = 2`, `q = 8`
**Output:** `6`
**Explanation:** Node `6` is the LCA of nodes `2` and `8`.

**Expected Time Complexity:** `O(Height of the BST)`
**Expected Auxiliary Space:** `O(1)`

---

### 📌 **Q3. Largest BST Subtree**

**Problem Statement:**
Given a binary tree, find the size of the **largest subtree** which is a Binary Search Tree (BST).

> **Note:** Size = Number of nodes in the subtree.

**Expected Time Complexity:** `O(n)`
**Expected Auxiliary Space:** `O(Height of the BST)`

#### ✅ Example 1:

```
        1
       / \
      4   4
     /     \
    6       8
```

**Output:** `1`
**Explanation:** All leaf nodes form individual BSTs of size 1. No larger BST exists.

#### ✅ Example 2:

```
        6
       / \
      6   2
         / \
        1   3
```

**Output:** `3`
**Explanation:** The subtree rooted at node `2` is a BST:

```
        2
       / \
      1   3
```

Size of this BST is `3`.