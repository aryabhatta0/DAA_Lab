#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin>>n>>m;
    vector<pair<pair<int, int>, int>> edges;  // {{u, v}, w}
    while(m--) {
        int u, v, w; cin>>u>>v>>w;
        edges.push_back({{u, v}, w});
    }

    vector<int> dist(n+1, 1e9);
    dist[1] = 0;
    for(int i=0; i<n-1; i++) {
        for(auto it: edges) {
            int u = it.first.first, v = it.first.second, w = it.second;
            dist[u] = min(dist[u], dist[v]+w);
            dist[v] = min(dist[v], dist[u]+w);
        }
    }

    bool negCycle=false;
    for(auto it: edges) {
        int u = it.first.first, v = it.first.second, w = it.second;
        if(dist[u] < dist[v] + w) {
            negCycle = true; break;
        }
        if(dist[v] < dist[u] + w) {
            negCycle = true; break;
        }
    }

    if(negCycle) cout << "-1\n";
    else cout << dist[n] << "\n";
    return 0;
}