## 💻 DAA Lab Test – 13th November 2024

### 📌 Q1. Longest Subarray with Sum Divisible by `k`

**Problem Statement:**
Given an array of integers and a positive integer `k`, find the **length of the longest subarray** such that the **sum of its elements is divisible by `k`**.

**✅ Example:**

```plaintext
Input:
  array = [7, 5, 4, 2, 3, 9]
  k = 5

Output:
  4

Explanation:
  The subarray [4, 2, 3, 9] has a sum of 18, which is divisible by 5.
```

**Time Complexity:** `O(N)`

---

### 📌 Q2. Sliding Window Minimum

**Problem Statement:**
Given an array of integers `A` and a window size `B`, find the **minimum value in each sliding window** of size `B` as it moves from the left to the right of the array.

**✅ Example:**

```plaintext
Input:
  A = [1, 4, 2, 6, -5]
  B = 3

Output:
  [1, 2, -5]

Explanation:
  Windows and their minimums:
    [1, 4, 2] → 1
    [4, 2, 6] → 2
    [2, 6, -5] → -5
```

**Time Complexity:** `O(N)`