#include <bits/stdc++.h>
using namespace std;

/*
O(n^2) sort
Iterate over each ith elements and put it at its correct place in arr[0...i-1]
*/

// 2 4 3
// 3 4 2
// 3 2 4

void insertionSort2(vector<int>& arr){
    int n=arr.size();
    for(int i=1; i<n; i++){
        int key=i;
        for(int j=i-1; j>=0; j--){
            if(arr[j]>arr[key]){
                swap(arr[j], arr[key]);
                key=j;
            }
            else break;
        }
    }
}

// Improvement Suggested: Instead of swap, you can directly put elements at its right pos by shifting it one right
// Assumption: Since elems of arr[0...i-1] will be already sorted when checking ith elem

void insertionSort(vector<int>& arr){
    int n=arr.size();
    
    for(int i=1; i<n; i++){
        int key=arr[i]; 
        int j=i-1;  // we'll check if j is at its correct place w.r.t key
        
        // Move elements of arr[0..i-1] that are greater than key
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];    // one place right
            j--;
        }
        
        arr[j+1]=key;   // place key at its corr place
    }
}

void print(vector<int> arr){
    for(auto it: arr) cout<<it<<" "; cout<<"\n";
}

int main()
{
    vector<int> arr{3, 2, 4, 10, 5};
    // vector<int> arr{3, 4, 10, 5, 2};
    insertionSort(arr);
    print(arr);

    return 0;
}