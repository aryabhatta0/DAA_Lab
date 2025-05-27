#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// return index of elem
// TC: O(logN)
// asc is a flag to know if we're finding elem in asc or desc part of array
int searchInRotatedArray(vector<int> arr, int elem, int lo, int hi, bool asc){
	int n=arr.size();
	int ans=-1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(asc){
			if(arr[mid]<=elem){
				lo=mid+1;
				ans=mid;
			} else hi=mid-1;
		} else {
			if(arr[mid]<=elem){
				hi=mid-1;
				ans=mid;
			} else lo=mid+1;
		}
	}
	
	return ans;
}

int findPeak(vector<int> arr){
	int n=arr.size();
	int lo=0, hi=n-1;
	int ans=-1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(arr[mid]<arr[mid+1]){	// inc part
			lo=mid+1;
			ans=mid+1;
		} 
		else {		// dec part
			hi=mid-1;
			ans=mid;
		}
	}
	
	return ans;
}

int main(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin>>a[i];
	int elemToFind; cin>>elemToFind;
	
	int peak = findPeak(a);
	cout << "Peak= " << peak << "\n";
	
	int elemInd = searchInRotatedArray(a, elemToFind, 0, peak, 1);
	if(elemInd==-1) elemInd = searchInRotatedArray(a, elemToFind, peak, n-1, 0);
	
	cout << "Ind of elem to find= " << elemInd << "\n";

	return 0;
}