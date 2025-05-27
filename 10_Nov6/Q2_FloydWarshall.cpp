#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin>>n>>m;
    vector<vector<int>> dist(n, vector<int>(n, 1e9)); // adjacency matrix
    for(int i=0; i<n; i++) dist[i][i] = 0;
    while(m--) {
        int u, v, w; cin>>u>>v>>w;
        dist[u][v] = dist[v][u] = min(dist[u][v], w);
    }

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // print output
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            cout << "shortest dist b/w " << i << " & " << j << " : " << dist[i][j] << "\n";
        }
    }
    return 0;
}