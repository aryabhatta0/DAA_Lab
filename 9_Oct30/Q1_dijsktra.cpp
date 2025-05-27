#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
using state = pair<int, int>; // {v, wt}

int n;
vector<vector<state>> adj;
vector<bool> vis;
vector<int> dist;

int sc;
void print() {
    cout << "Source: " << sc << "\n";
    for(int i=0; i<n; i++) {
        cout << "Dist of " << i << ": " << dist[i] << "\n";
    }
}

void dijkstra(int sc) {

    priority_queue<pair<int, int>> pq; // {-dist, node}
    dist[sc]=0;
    pq.push({0, sc});

    while(!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        int u = curr.second;

        if(vis[u]) continue;
        vis[u] = true;

        for(auto it: adj[u]) {
            int v = it.first, wt = it.second;
            if(dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main() {
    int m;
    cin >> n >> m; // n = number of nodes, m = number of edges

    adj.assign(n, {});
    vis.assign(n, false);
    dist.assign(n, INF);

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        // For undirected graph, add:
        // adj[v].push_back({u, wt});
    }

    cin >> sc;
    dijkstra(sc);
    print();

    return 0;
}