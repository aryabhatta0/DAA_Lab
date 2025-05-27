
**Q4. (Bonus)** *Implement an algorithm to find the k-th smallest element in a given array using “Median of Medians”*.

**Follow the steps below:**

1. **Divide the Array**: Divide the array into subarrays of size 5 (except the last one, which can have fewer elements).

2. **Find Medians**: For each subarray, find the median element using an efficient algorithm (e.g., sorting or selection).

3. **Calculate Median of Medians**: Find the median of the medians recursively from step 2.

4. **Partitioning**: Use the calculated median of medians as a pivot to partition array.

5. **Recursion**:

   * a. If the pivot index is i and *i < k* then recursively selects the k-th element in the lower part
   * b. If the pivot index is i and *i > k* then recursively selects the (k-i-1)th smallest element in the upper part
   * c. If *i == k* then return the pivot element

**Example**:

* **Input**: arr = \[9, 3, 7, 5, 6, 4, 8], k = 3
* **Output**: 5

**Gmail**: [labdaa05@gmail.com](mailto:labdaa05@gmail.com)