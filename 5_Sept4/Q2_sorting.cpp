#include <bits/stdc++.h>
using namespace std;

void sort(vector<int>& arr1, vector<int>& arr2){
    int m = arr1.size();
    int n = arr2.size();

    set<int> st2;
    for(auto it: arr2) st2.insert(it);

    map<int, int> mp;  // freq of elements of arr2 present in st2
    vector<int> vec;   // elements in arr1 not in st2
    for(auto it: arr1){
        if(st2.find(it) != st2.end()) mp[it]++;
        else vec.push_back(it);
    }

    sort(vec.begin(), vec.end());

    int i = 0;
    for(auto it: arr2){
        while(mp[it]--){
            arr1[i++] = it;
        }
    }

    for(auto v: vec){
        arr1[i++] = v;
    }
}

int main(){
    int m; cin >> m;
    vector<int> arr1(m);
    for(int i = 0; i < m; i++) cin >> arr1[i];

    int n; cin >> n;
    vector<int> arr2(n);
    for(int i = 0; i < n; i++) cin >> arr2[i];

    sort(arr1, arr2);
    for(auto it: arr1) cout << it << ' '; cout << '\n';
}
