
## 💻 DAA Lab - 6th November 2024

### 📌 Q1. **Implement Bellman-Ford Algorithm** for undirected graphs.

### 📌 Q2. **Implement Floyd-Warshall Algorithm** for undirected graphs.

---
### 📌 Q3. City With the Smallest Number of Reachable Cities

There are `n` cities numbered from `0` to `n-1`. Given the array `edges` where
`edges[i] = [from_i, to_i, weight_i]` represents a bidirectional and weighted edge between cities `from_i` and `to_i`, and given the integer `distanceThreshold`.

Return the city with the **smallest number of cities** that are reachable through some path and whose distance is at most `distanceThreshold`.
If there are multiple such cities, return the city with the **greatest number**.

> Notice that the distance of a path connecting cities `i` and `j` is equal to the sum of the edges' weights along that path.

### ✅ Example:
```plaintext
Input:
n = 4
edges = [[0,1,3], [1,2,1], [1,3,4], [2,3,1]]
distanceThreshold = 4

Output: 3
```