#include <bits/stdc++.h>
using namespace std;

// create partition so that elem>piv are on the left and return the currIndex of pivot
int partition(vector<int>& arr, int lo, int hi, int pivInd){
	int pivot = arr[pivInd];
	int j=lo;	// iter to put the elems higher than piv at
	
	for(int i=lo; i<=hi; i++){
		if(arr[i]>pivot){
			swap(arr[i], arr[j]);
			if(j==pivInd) pivInd=i;
			j++;
		}	
	}
	
	swap(arr[pivInd], arr[j]);	// swap pivot at its corr place
	return j;
}

int quickSelect(vector<int>& arr, int k, int lo, int hi){
	// chose pivot
	int pivInd=hi;
	
	// partition
	int pi = partition(arr, lo, hi, pivInd);
	
	// recursion
	// pi is the correct index of pivot
	if(pi==k) return arr[pi];
	else if(pi>k) return quickSelect(arr, k, lo, pi-1);
	else return quickSelect(arr, k, pi+1, hi);
}

int getKthLargest(vector<int>& arr, int k){
	return quickSelect(arr, k-1, 0, arr.size()-1);
}

void print(vector<int> arr){
	cout << "Arr: ";
	for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
	cout << "\n";
}

int main(){
	int n; cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	int k; cin>>k;
	
	cout << getKthLargest(arr, k) << "\n";
	print(arr);
	return 0;
}