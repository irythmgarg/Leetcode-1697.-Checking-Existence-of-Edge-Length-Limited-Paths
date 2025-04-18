# Leetcode-1697.-Checking-Existence-of-Edge-Length-Limited-Paths
# 📦 Distance Limited Paths Exist

This repository contains a highly optimized solution for checking **distance-limited paths** between pairs of nodes in an undirected weighted graph.

It uses **Disjoint Set Union (DSU)** and an **offline query processing** technique to achieve excellent performance.

---

## ❓ Problem Statement

You're given:
- A graph of `n` nodes (0 to n-1)
- An `edgeList` of weighted undirected edges
- A list of `queries`, each asking if there's a path from node `u` to node `v` with all edges on that path having weight **strictly less than a limit `limit`**.

Return an array of booleans where each entry corresponds to the result of that query.

---

## 🚀 Approach

### 🧱 Disjoint Set Union (DSU) + Offline Queries

1. **Sort edges** by weight.
2. **Sort queries** by limit.
3. **Process queries** in increasing order of their limits while adding edges to DSU that satisfy the weight constraint.
4. For each query, check if `u` and `v` belong to the same component.

This allows answering each query in near-constant time after preprocessing.

---

## 🧠 Key Functions

- **`find(x)`** → Finds the leader of node `x` using path compression.
- **`unite(x, y)`** → Merges sets using union by rank.
- **`distanceLimitedPathsExist()`** → Main function using offline query strategy.

---

## 📊 Time & Space Complexity

| Metric        | Complexity                 |
|---------------|-----------------------------|
| Time          | O((E + Q) log(E + Q))       |
| Space         | O(N)                        |
- `E` = number of edges  
- `Q` = number of queries  
- `N` = number of nodes

---

## 🧪 Example

```cpp
Input:
n = 5
edgeList = [[0,1,2],[1,2,4],[2,3,6],[0,4,8]]
queries = [[0,3,5],[0,4,10]]

Output:
[false, true]

🔧 How It Works
Queries are sorted by limit.
Edges are processed in order, joining nodes where edge weight < limit.
If two nodes are in the same component in DSU, a path exists under the limit.
