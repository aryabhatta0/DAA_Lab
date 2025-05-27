#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<vector<int>> arr, int tar) {
    int m = arr.size(), n = arr[0].size();
    int lo = 0, hi = m * n - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        int row = mid / n;
        int col = mid % n;

        if (arr[row][col] == tar) return true;
        else if (arr[row][col] < tar) lo = mid + 1;
        else hi = mid - 1;
    }

    return false;
}

int main() {
    int m, n; cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    }

    int tar; cin >> tar;
    cout << (binarySearch(arr, tar) ? "true" : "false") << "\n";
    return 0;
}
