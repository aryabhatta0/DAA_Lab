#include<bits/stdc++.h>
using namespace std;

class disjointSets {
    int n;
    vector<int> parent, rank;

    int find(int node) {
        if(node==parent[node]) return node;
        return parent[node] = find(parent[node]);
    }

public:
    disjointSets(int n) {
        this->n = n;
        parent.resize(n); rank.resize(n);
        for(int i=0; i<n; ++i) {
            parent[i] = i;
            rank[i] = 1;    // by size
        }
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if(x==y) return;

        if(rank[x]==rank[y]) {
            parent[y] = x;
            rank[x] += rank[y];
        } else {
            parent[x] = y;
            rank[y] += rank[x];
        }
    }

    bool isSame(int x, int y) {
        return find(x)==find(y);
    }
};

void MST(int n, vector<pair<int, pair<int, int>>> edges) {
    // sort edges by weight
    sort(edges.begin(), edges.end());

    // disjointSets to account for connected nodes
    disjointSets uf(n);

    int cost=0;
    vector<vector<int>> edgeUsed;
    for(auto it: edges) {
        int w = it.first;
        int u = it.second.first;
        int v = it.second.second;

        // if u, v not already connected, merge them using this edge
        if(!uf.isSame(u, v)) {
            uf.merge(u, v);
            cost += w;
            edgeUsed.push_back({u,v});
        }
    }

    // print ans
    cout << "Cost of MST: " << cost << '\n';
    cout << "Edges Involved: ";
    for(auto it : edgeUsed) {
        cout << "<" << it[0] << ", " << it[1] << "> ";
    }
    cout << "\n";
}

int main() {
    int n; cin>>n;
    vector<pair<int, pair<int, int>>> edges;   // {w, {u,v}}
    int e; cin>>e;
    while(e--) {
        int u, v, w; cin>>u>>v>>w;
        edges.push_back({w, {u, v}});
    }

    MST(n, edges);
}
