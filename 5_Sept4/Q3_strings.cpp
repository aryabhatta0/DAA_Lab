#include <bits/stdc++.h>
using namespace std;

string solve(string s, string t){
    map<char, int> mp;
    for(auto it: t) mp[it]++;

    int n = s.size();
    int len = 1e9, start = 0;
    for(int i = 0; i < n; i++){
        map<char, int> curr;
        int formed = 0;
        int next_useful = i;
        for(int j = i; j < n; j++){
            bool flag = true;
            if(mp.find(s[j]) == mp.end()) { next_useful++; flag = false; }

            curr[s[j]]++;
            if(mp.find(s[j]) != mp.end() && mp[s[j]] == curr[s[j]]) formed++;

            if(formed == mp.size()){
                if(len > j - i + 1){
                    len = j - i + 1;
                    start = i;
                }
            }
        }
        i = next_useful;
    }

    if(len != 1e9) return s.substr(start, len);
    return "";
}

int main(){
    string s, t;
    cin >> s >> t;
    cout << solve(s, t) << '\n';
}
