#include <bits/stdc++.h>
using namespace std;

// if it's possible to distribute books so that no student gets more than 'mid' pages
bool check(int mid, vector<int> books, int numStudents){
	
	int cnt=1;	// cnt of min students req so that each student will get <=mid pages
	int currPages=0;
	for(auto b: books){
		if(currPages + b <= mid){
			currPages+=b;
		} else {
			cnt++;
			currPages=b;
		}
		if(cnt>numStudents) return 0;
	}
	
	if(cnt<=numStudents) return 1;
	return 0;

} 

// minimize the maximum pages read by a student
int solve(vector<int> books, int numStudents){
	// binarySearch on ans
	int lo=0, hi=0;
	for(auto b: books) {
		lo=max(lo,b);
		hi+=b;
	}
	
	int ans=-1;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		// debug
		bool flag=check(mid, books, numStudents);
		// cout<<"checking for mid="<<mid<< " : " << flag << "\tlo="<<lo<<" hi="<<hi<< "\n";
		if(flag){
			ans=mid;
			hi=mid-1;
		} else lo=mid+1;
	}
	return ans;
}


int main(){
	cout << "Enter book:\n";
	int n; cin>>n;
	vector<int> books(n);
	for(int i=0; i<n; i++) cin>>books[i];
	
	cout << "Enter num students: \n";
	int m; cin>>m;
	
	cout << "Output: " << solve(books, m) << "\n";
	return 0;
}