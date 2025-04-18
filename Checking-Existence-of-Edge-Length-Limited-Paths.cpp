class Solution {
public:
    vector<int> parents;  // Parent array for DSU
    vector<int> ranks;    // Rank array for DSU (for union by rank)

    // Path Compression-based Find function
    int find(int x) {
        if (parents[x] != x)
            parents[x] = find(parents[x]);
        return parents[x];
    }

    // Union by rank
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (ranks[px] < ranks[py]) {
            parents[px] = py;
        } else if (ranks[px] > ranks[py]) {
            parents[py] = px;
        } else {
            parents[py] = px;
            ranks[px]++;
        }
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        // Sort all edges by their weights (ascending order)
        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        // Augment queries with their original index
        vector<tuple<int, int, int, int>> newQueries;
        for (int i = 0; i < queries.size(); i++) {
            newQueries.push_back({queries[i][0], queries[i][1], queries[i][2], i});
        }

        // Sort queries based on the limit
        sort(newQueries.begin(), newQueries.end(), [](const auto& a, const auto& b) {
            return get<2>(a) < get<2>(b);
        });

        // Initialize DSU
        parents.resize(n);
        ranks.resize(n);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
            ranks[i] = 0;
        }

        vector<bool> ans(queries.size());
        int j = 0; // Edge pointer

        // Process queries in increasing order of limits
        for (const auto& [u, v, limit, index] : newQueries) {
            // Union all edges with weight < current limit
            while (j < edgeList.size() && edgeList[j][2] < limit) {
                unite(edgeList[j][0], edgeList[j][1]);
                j++;
            }

            // Check if u and v are in the same component
            ans[index] = (find(u) == find(v));
        }

        return ans;
    }
};
