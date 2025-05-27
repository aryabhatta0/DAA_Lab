#include <bits/stdc++.h>
using namespace std;

// check if there exist p pairs with diff >= mid
bool check(int mid, int p, vector<int>& nums) {
    int n = nums.size();
    int cnt = 0;

    for (int i = 1; i < n; i++) {
        if (nums[i] - nums[i - 1] >= mid) {
            cnt++;
            i++;
        }
        if (cnt >= p) return true;
    }
    return false;
}

// binary search on ans
int solve(vector<int>& nums, int p) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int lo = 0, hi = nums[n - 1] - nums[0];
    int ans = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid, p, nums)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int p; cin >> p;

    cout << solve(nums, p) << "\n";
    return 0;
}
