// Older version

// ORDER STATISTICS
/** Things covered:
 * Quick Sort
 * Kth smallest element using heap
 * Quick Select
 */

#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////////////// QUICK SORT ////////////////////////////////////////

// returns the pivot index after partitioning the array 
int partition(vector<int>& arr, int lo, int hi, int pivInd){
    int pivot = arr[pivInd];  
    int j=lo;   // iterator to put elements <=piv at
    
    for(int i=lo; i<=hi; i++){
        if(arr[i] < pivot){
            swap(arr[i], arr[j]);
            if(j==pivInd) pivInd=i;
            j++;
        }
    }
    
    swap(arr[pivInd], arr[j]);  // put piv at its correct place
    return j;   // index of pivot
}

// We'll be doing in O(1) space complexity, hence lo & hi required
void quickSort(vector<int>& arr, int lo, int hi){
    if(lo>=hi) return;
    
    // chose pivot
    int pivInd=hi;  // standard pivot
    // int pivInd=min(lo+3, hi);    // testing code
    
    // partition
    int piv = partition(arr, lo, hi, pivInd);
    
    // recursive sort the subarrays
    quickSort(arr, lo, piv-1);
    quickSort(arr, piv+1, hi);
}

//////////////////////////////////////// Kth Smallest Element ////////////////////////////////////////

int getKthSmallest(vector<int> arr, int k){
    
    priority_queue<int> pq;
    for(auto it: arr){
        if(pq.size()<k) pq.push(it);
        else {
            if(it<pq.top()){
                pq.pop();
                pq.push(it);
            }
            // else continue;
        }
    }
    
    return pq.top();
}

// find element at kth ind if the array'll be sorted
int quickSelect(vector<int> arr, int k, int lo, int hi){
    if(lo>hi) return -1;
    // if(lo==hi) return arr[lo];
    
    // chose a pivot
    int pivInd=hi;
    
    // partition array
    int pi = partition(arr, lo, hi, pivInd);
    
    // recursively search in one of the halfs
    if(pi==k) return arr[pi];
    else if(pi>k) return quickSelect(arr, k, lo, pi-1);
    else return quickSelect(arr, k, pi+1, hi);
}


void print(vector<int> arr){
    cout<<"array: ";
    for(auto it: arr) cout<<it<<" ";
    cout<<"\n";
}

int main()
{
    // vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> arr = {-3, 7, -8, 5, -2, 1, -9, 5, 0, 6};
    // vector<int> arr = {1000, -200, 150, 7, 89, 1, 0, -100, 500, 3, 45, 67, 23, 98, -76, 1023, 56, -450, 600};

    // vector<int> arr{7,10,4,3,20,15};
    int k=7;
    // cout << getKthSmallest(arr, k) << "\n";
    cout << quickSelect(arr, k-1, 0, arr.size()-1) << "\n";
    
    
    quickSort(arr, 0, arr.size()-1); print(arr);
    return 0;
}