#include <bits/stdc++.h>
using namespace std;

double maximizeValue(vector<int>& weights, vector<int>& values, int cap) {
    int n = weights.size();

    vector<pair<double, int>> vec;  // val per unit wt, wt
    for (int i = 0; i < n; i++) {
        vec.push_back({(1.0 * values[i]) / (weights[i]), weights[i]});  // adding -ve vals to vec
    }

    // sort
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    double wt = 0;
    double val = 0;
    for (auto it : vec) {
        if (wt + it.second <= cap) {
            wt += it.second;
            val += (it.second * it.first);
        } else {
            // break the wt
            val += (cap - wt) * (it.first);
            break;
        }
    }

    return val;
}

int main() {
    int n; cin >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) cin >> weights[i];

    vector<int> values(n);
    for (int i = 0; i < n; i++) cin >> values[i];

    int capacity; cin >> capacity;

    cout << setprecision(3);
    cout << maximizeValue(weights, values, capacity) << "\n";

    return 0;
}
