#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> dp;
// dp[lev][state] = max profit you can achieve in lev...n when you're in 'state' on levth day
// state = 0  can buy   actions: buy/skip
// state = 1  can sell  actions: sell/slip
int rec(int lev, int state, vector<int>& prices, int fee) {
    // base case
    if(lev==n) {
        if(state==0) return 0;
        else return -1e9; // A very small number, assuming profit can be negative
    }
    // cache check
    if(dp[lev][state]!=-1) return dp[lev][state];

    // transition
    int ans;
    if(state==0) {      // can buy: skip / buy
        ans = max(rec(lev+1, state, prices, fee), rec(lev+1, 1-state, prices, fee) - prices[lev] - fee);
    }
    else {              // can sell: skip / sell
        ans = max(rec(lev+1, state, prices, fee), rec(lev+1, 1-state, prices, fee) + prices[lev]);
    }
    // save and return
    return dp[lev][state] = ans;
}

int main() {
    cin>>n;
    vector<int> prices(n);
    for(int i=0; i<n; i++) cin>>prices[i];
    int fee; cin>>fee;

    dp.resize(n, vector<int>(2, -1));
    cout << "Max profit: " << rec(0, 0, prices, fee) << "\n";
    return 0;
}