#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B){
	vector<vector<int>> res(2, vector<int>(2));
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			int sum=0;
			for(int k=0; k<2; k++) sum+=A[i][k]*B[k][j];
			res[i][j]=sum;
		}
	}
			
	return res;
}

vector<vector<int>> power(vector<vector<int>> A, int n){
	if(n==1) return A;
	
	if(n%2!=0) return multiply(A, power(A, n-1));
	else return power(multiply(A, A), n/2);
}

void print(vector<vector<int>> A){
	cout << "Matrix: \n";
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++) cout<<A[i][j]<<" ";
		cout<<"\n";
	}
}

/** A^n:
F_n+1 F_n
F_n	  F_n-1
*/
int getFibonacci(int n){
	vector<vector<int>> A = {{1,1},{1,0}};
	
	vector<vector<int>> B = power(A, n);
	print(B);
	return B[0][1];
}



int main(){
	int n; cin>>n;
	cout << getFibonacci(n) << "\n";
	return 0;
}