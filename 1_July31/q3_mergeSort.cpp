#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Implement Merge Sort Recursively

void mergeSort(vector<int>& a, int lo, int hi){
	if(lo>=hi) return;

	int mid = (lo+hi)/2;
	mergeSort(a, lo, mid);
	mergeSort(a, mid+1, hi);
	
	vector<int> b;
	int i=lo, j=mid+1;
	while(i<=mid && j<=hi){
		if(a[i]<a[j]) {
			b.push_back(a[i]); i++;
		} else {
			b.push_back(a[j]); j++;
		}
	}
	
	for(; i<=mid; i++) b.push_back(a[i]);
	for(; j<=hi; j++) b.push_back(a[j]);
	
	// Copy the sorted b into a
	for (i = lo; i <= hi; i++) a[i] = b[i-lo];
}



int main(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin>>a[i];
	
	mergeSort(a, 0, n-1);
	cout<<"Sorted Array: "; for(int i=0; i<n; i++) cout<<a[i]<<" "; cout<<"\n";
	return 0;
}