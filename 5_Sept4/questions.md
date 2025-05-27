## 💻 DAA Lab 4 – 4th Sept 2024

### 📌 Q2. Relative Sorting of Two Arrays

**Problem Statement:**  
Given two arrays `arr1[]` and `arr2[]` of size *m* and *n*, the task is to sort `arr1[]` such that the relative order among the elements matches the order in `arr2[]`.  
For elements not present in `arr2[]`, append them at the end in **sorted order**.

> **Note:** If elements are repeated in the second array, consider their first occurrence only.

### ✅ Example:
**Input:**  
`arr1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}`  
`arr2[] = {2, 1, 8, 3}`

**Output:**  
`arr1[] = {2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9}`

### Constraints:
- `1 <= n, m <= 10^6`

---

### 📌 Q3. Minimum Window Substring

**Problem Statement:**  
Given two strings `s` and `t` of lengths *m* and *n* respectively, return the **minimum window substring** of `s` such that every character in `t` (including duplicates) is included in the window.  
If there is no such substring, return the empty string `""`.

### Constraints:
- `1 <= m, n <= 10^5`
- `s` and `t` consist of uppercase and lowercase English letters.

### ✅ Example:
**Input:**  
`s = "ADOBECODEBANC"`  
`t = "ABC"`

**Output:**  
`"BANC"`
