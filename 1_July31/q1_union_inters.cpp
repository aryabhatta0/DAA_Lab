#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Aux Space: O(1)
// TC: O(n+m)
void getUnionAndIntersection(vector<int> a, vector<int> b, vector<int>& uni, vector<int>& inter){
	int n = a.size();
	int m = b.size();
	int i=0, j=0;
	
	int last = -1;
	while(i<n && j<m){
		if(a[i]<b[j]){
			if(last!=a[i]) uni.push_back(a[i]); 
			last = a[i]; i++;
		} else if(a[i]>b[j]){
			if(last!=b[j]) uni.push_back(b[j]); 
			last = b[j]; j++;
		} else {
			if(last!=a[i]) {
				uni.push_back(a[i]);
				inter.push_back(a[i]); 
			}
			last = a[i];
			i++; j++;
		}
	}
	
	// add remaining
	for(; i<n; i++) uni.push_back(a[i]);
	for(; j<m; j++) uni.push_back(b[j]);
}

int main(){
	int n, m; cin>>n>>m;
	vector<int> a(n), b(m);
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<m; i++) cin>>b[i];
	
	vector<int> uni, inter;
	getUnionAndIntersection(a, b, uni, inter);
	
	// printing output
	cout << "UNION:"; for(int i=0; i<uni.size(); i++) cout<<uni[i]<<" "; cout<<"\n";
	cout << "INTERSECTION:"; for(int i=0; i<inter.size(); i++) cout<<inter[i]<<" "; cout<<"\n";

	return 0;
}