#include<bits/stdc++.h>
using namespace std;

void MST(int n, priority_queue<pair<int, pair<int, int>>> pq) {
    int cost = 0;
    vector<vector<int>> edgesUsed;
    vector<int> visited(n, false);

    while (!pq.empty()) {
        auto it = pq.top(); pq.pop();
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (visited[u] && visited[v]) continue;
        visited[u] = true;
        visited[v] = true;

        cost += wt;
        edgesUsed.push_back({u, v});
    }

    // print ans
    cout << "Cost of MST: " << cost << "\n";
    cout << "Edges Involved: ";
    for (auto it : edgesUsed) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << "\n";
}

int main() {
    int n; cin >> n;
    vector<pair<int, pair<int, int>>> edges; // {w, {u,v}}
    priority_queue<pair<int, pair<int, int>>> pq; // {w, {u,v}}

    int e; cin >> e;
    while (e--) {
        int u, v, w; cin >> u >> v >> w;
        pq.push({w, {u, v}}); // for min heap
    }

    MST(n, pq);
}
