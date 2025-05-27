## 💻 DAA Lab – 7 August 2024

### 📌 Problems


### **1. Matrix Multiplication Check & Compute**

Given two matrices:

* **A** of size `(m1 × n1)`
* **B** of size `(m2 × n2)`

🔍 **Task:**
Check if the multiplication of A and B is possible. If yes, compute and return the result of `A × B`.

---

### **2. Book Allocation Problem**

You are given an array `arr[]` where `arr[i]` represents the number of pages in the *i-th* book.
There are `m` students, and the goal is to allocate books to these students under the following constraints:

#### ✅ Constraints:

* Each student must be allocated **at least one book**.
* Each book must be allocated to **only one student**.
* **Books must be allocated contiguously** (i.e., no skipping books).

🎯 **Objective:**
Allocate the books such that the **maximum number of pages assigned to a student is minimized**.

#### 🧠 Complexity:

* **Time Complexity:** `O(n log n)`
* **Auxiliary Space:** `O(1)`

#### 📘 Example:

* **Input:** `arr = [15, 17, 20]`, `m = 2`
* **Output:** `32`

---

### **3. Randomized QuickSort**

Implement the **Randomized QuickSort** algorithm to sort a given array in ascending order.

> 💡 *Hint:* Randomized QuickSort improves the performance of QuickSort in worst-case scenarios by choosing a pivot at random instead of a fixed strategy.

