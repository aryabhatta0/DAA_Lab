#include <bits/stdc++.h>
using namespace std;

void multiplication(vector<vector<int>>& mat1, int m1, int n1, vector<vector<int>>& mat2, int m2, int n2){
	if(n1!=m2) {
		cout << "Multiplication not possible\n";
		return;
	}
	
	int res[m1][n2];
	for(int i=0; i<m1; i++){
		for(int j=0; j<n2; j++){
			int curr=0;
			for(int k=0; k<n1; k++){
				curr += mat1[i][k] * mat2[k][j];
			}
			res[i][j]=curr;
		}
	}
	
	// print output
	cout << "Multiplication of matrices A & B: \n";
	for(int i=0; i<m1; i++){
		for(int j=0; j<n2; j++) cout << res[i][j] << " ";
		cout << "\n";
	}
}

int main(){
	cout << "Input matrix 1:\n";
	int m1, n1; cin>>m1>>n1;
	vector<vector<int>> mat1(m1, vector<int>(n1));
	for(int i=0; i<m1; i++){
		for(int j=0; j<n1; j++) cin>>mat1[i][j];
	}
	
	cout << "Input matrix 2:\n";
	int m2, n2; cin>>m2>>n2;
	vector<vector<int>> mat2(m2, vector<int>(n2));
	for(int i=0; i<m2; i++){
		for(int j=0; j<n2; j++) cin>>mat2[i][j];
	}
	
	multiplication(mat1, m1, n1, mat2, m2, n2);

	return 0;
}