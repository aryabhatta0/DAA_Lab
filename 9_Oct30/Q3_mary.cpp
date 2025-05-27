#include <bits/stdc++.h>
using namespace std;

struct disjointSets {
    std::vector<int> parent;
    std::vector<int> rank;      // union-by-size

    disjointSets(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);      // initially size 1
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    bool isSame(int i, int j) {
       return find(i) == find(j);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank[x] >= rank[y]) {
            parent[y] = x;
            rank[x] += rank[y];
        } else {
            parent[x] = y;
            rank[y] += rank[x];
        }
    }
};

int main() {
    int n, m; std::cin >> n >> m;
    std::vector<std::pair<int, std::pair<int, int>>> edges; // {weight, {u, v}}
    for (int i = 0; i < m; i++) {
        int u, v, w; std::cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    int sc = 1, en = n;
    disjointSets dsu(n + 1);

    std::sort(edges.begin(), edges.end());

    int ans;
    for (int i = m - 1; i >= 0; i--) {
        auto curr = edges[i];
        int u = curr.second.first;
        int v = curr.second.second;

        if (!dsu.isSame(sc, en)) {
            std::cout << "merging " << u << " " << v << "\n";
            dsu.merge(u, v);
            ans = curr.first;
        } else break;
    }

    std::cout << "Mary's speed= " << ans << "\n";
    return 0;
}