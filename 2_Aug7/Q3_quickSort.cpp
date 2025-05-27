#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& vec){
	for(int i=0; i<vec.size(); i++) cout<<vec[i]<<" "; cout<<"\n";
}

void quickSort(vector<int>& vec, int l, int r){
	// base case
	if(l>=r) return;
	
	// STEP1: random pivot selection
	int ind = l + rand() % (r-l);
	int piv = vec[ind];
	
	// STEP2: partitioning - rearrange array
	int cnt=0;
	for(int i=l; i<=r; i++){
		if(vec[i]<=piv) cnt++;
	}
	int pivInd = l+cnt-1;
	
	// swap piv to pivInd
	int temp=vec[pivInd];
	vec[pivInd]=piv;
	vec[ind]=temp;
	
	int i=l, j=pivInd+1;
	for(int i=l; i<=pivInd; i++){
		if(vec[i]>piv){
			while(vec[j]>piv) j++;
			// swap ith & jth elem
			int temp=vec[i];
			vec[i]=vec[j];
			vec[j]=temp;
		}
	}
	
	// STEP3: recursion
	quickSort(vec, l, pivInd-1);
	quickSort(vec, pivInd+1, r);
}

int main(){
	int n; cin>>n;
	vector<int> vec(n);
	for(int i=0; i<n; i++) cin>>vec[i];
	
	quickSort(vec, 0, n-1);
	cout<<"Sorted Array: "; print(vec);
	return 0;
}