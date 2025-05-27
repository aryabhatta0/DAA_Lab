#include <bits/stdc++.h>
using namespace std;

int main() {
    // city with smallest number of reachable city
    // dist[i][j] : i se sabhi ka dist dega
    // isme cnt of cities with dist < thresh
    int n, m; cin>>n>>m;
    vector<vector<int>> dist(n, vector<int>(n, 1e9));  // adjacency matrix
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

    int thresh; cin>>thresh;

    int ans, miniCnt=1e9;
    for(int i=0; i<n; i++) {
        int cnt=0;
        for(int j=0; j<n; j++) {
            if(dist[i][j] <= thresh) cnt++;
        }

        if(miniCnt >= cnt) {
            miniCnt = cnt;
            ans = i;
        }
    }
    cout << "ans: " << ans << "\n";

    return 0;
}