#include <bits/stdc++.h>
using namespace std;

// return max product of 3 nums
int getMaxProd(vector<int> arr){
	int n=arr.size();
	sort(arr.begin(), arr.end());
	return max(arr[0]*arr[1]*arr[n-1], arr[n-3]*arr[n-2]*arr[n-1]);
}

int getMaxProd2(vector<int> arr){
	priority_queue<int> maxHeap(arr.begin(), arr.end());
	int ans1=1;
	int ans2=maxHeap.top();
	for(int i=0; i<3; i++) {
		ans1*=maxHeap.top(); 
		maxHeap.pop();
	}
	
	priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());
	ans2*=minHeap.top(); minHeap.pop();
	ans2*=minHeap.top(); minHeap.pop();
	
	return max(ans1, ans2);
}


int main(){
	int n; cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	
	cout << getMaxProd2(arr) << "\n";
	return 0;
}