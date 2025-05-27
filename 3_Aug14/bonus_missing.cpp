#include <bits/stdc++.h>
using namespace std;

int cnt=0;	// cnt of non-positive num

void print(vector<int> arr){
	cout << "Arr: ";
	for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
	cout << "\n";
}

// create partition so that elem>piv are on the left and return the currIndex of pivot
int partition(vector<int>& arr, int lo, int hi, int pivInd){
	if(lo>=hi) return pivInd;
	
	int pivot = arr[pivInd];
	int j=lo;	// iter to put the elems higher than piv at
	
	for(int i=lo; i<=hi; i++){
		if(arr[i]<pivot){
			swap(arr[i], arr[j]);
			if(j==pivInd) pivInd=i;
			j++;
		}	
	}
	
	swap(arr[pivInd], arr[j]);	// swap pivot at its corr place
	return j;
}

// return the smallest positive number missing from the array
int getMissing(vector<int>& arr, int lo, int hi){
	if(cnt==arr.size()) return 1;
	if(lo>hi) return -1;
	if(arr.size()==1){
		if(arr[0]==1) return 2;
		else return 1;
	}	
	
	if(lo==hi) {
		if(lo==cnt+arr[lo]-1) return arr[lo]+1;
		else return arr[lo-1]+1;
	}

	// pivot
	int pivInd=hi;
	
	// partition
	int pi = partition(arr, lo, hi, pivInd);
	// print(arr);
	// cout << "pi="<<pi << " hi="<<hi<<"\n";
	
	// if(pi==hi) return arr[hi]+1;
	if(arr[pi]<=0 || pi==cnt+arr[pi]-1) return getMissing(arr, pi+1, hi);
	else return getMissing(arr, lo, pi-1);
}

int main(){
	int n; cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin>>arr[i];
		if(arr[i]<=0) cnt++;
	}
	
	cout << getMissing(arr, 0, arr.size()-1) << "\n";
	print(arr);
	return 0;
}