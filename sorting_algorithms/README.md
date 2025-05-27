# Sorting Algorithms

## Insetion Sort
Builds the final sorted array one item at a time. It iterates through the input elements and grows a sorted output list.

**TC:** Best: O(n), Average: O(n^2), Worst: O(n^2)

## Merge Sort 
Divide-and-conquer algorithm that divides the input array into two halves, recursively sorts both halves, and then merges the sorted halves.

**TC:** Best: O(n log n), Average: O(n log n), Worst: O(n log n)

## Quick Sort
A divide-and-conquer algorithm that picks a pivot element and partitions the array around the pivot, placing smaller elements before it and larger elements after it.

**TC:** Best: O(n log n), Average: O(n log n), Worst: O(n^2)

## Heap Sort
Uses a binary heap data structure to sort elements. It first builds a max heap from the input data, then repeatedly extracts the maximum element and places it at the end of the sorted array.

**TC:** Best: O(n log n), Average: O(n log n), Worst: O(n log n)

## Quick Select
A selection algorithm to find the k-th smallest element in an unordered list. It is related to quicksort and works by partitioning the array.