#include<bits/stdc++.h>
using namespace std;

// returns length of longest palindromic subseq of s[i...j]
int rec(int i, int j, string& s, vector<vector<int>>& dp) {
    // base case
    if(i > j) return 0;
    if(i == j) return 1;

    // cache check
    if(dp[i][j] != -1) return dp[i][j];

    // transition - try out all possibilities
    int ans = max(rec(i, j-1, s, dp), rec(i+1, j, s, dp));
    if(s[i] == s[j]) ans = max(ans, 2 + rec(i+1, j-1, s, dp));

    // save and return
    return dp[i][j] = ans;
}

int main() {
    string str; cin >> str;

    int n = str.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    cout << "Size of longest palindrome: " << rec(0, n-1, str, dp) << "\n";
}
