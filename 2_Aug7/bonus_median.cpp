#include <bits/stdc++.h>
using namespace std;

double getMedian(vector<int> nums1, int n1, vector<int> nums2, int n2){
	int n = n1+n2;
	
	if(n%2==0){
		// n/2, n/2 +1th elem
		int val1, val2;
		
		int ind=n/2;
		if(ind<=n1) val1= nums1[ind-1];
		else val1= nums2[ind-n1-1];
		
		ind+=1;
		if(ind<=n1) val2= nums1[ind-1];
		else val2= nums2[ind-n1-1];
		
		return (val1+val2)/2.0;
	} else {
		// return n/2 +1 th elem
		int ind = (n/2) +1;
		if(ind<=n1) return nums1[ind-1]/1.0;
		else return nums2[ind-n1-1]/1.0;
	}
}

int main(){
	int n; cin>>n;
	vector<int> nums1(n);
	for(int i=0; i<n; i++) cin>>nums1[i];
	
	int m; cin>>m;
	vector<int> nums2(m);
	for(int i=0; i<m; i++) cin>>nums2[i];
	
	cout<<"Median: " << getMedian(nums1, n, nums2, m) << "\n";
	return 0;
}