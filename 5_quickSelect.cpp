#include <bits/stdc++.h>
using namespace std;

// 
int partition(vector<int>& arr, int lo, int hi, int pivInd){
    int piv = arr[pivInd];
    int i=lo;
    int j=hi;   // iter to put elems >piv at
    
    while(i<=j){
        if(arr[i]>piv){
            swap(arr[i], arr[j]);
            if(j==pivInd) pivInd=i;
            j--;
        } else i++;
    }
    
    swap(arr[j], arr[pivInd]); // put piv at its corr place
    return j;
}

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

// QuickSelect implementation to find the k-th smallest element
// O(n) average time complexity
int quickSelect(vector<int>& arr, int k, int lo, int hi){
    if (lo == hi) return arr[lo];  // Only one element, must be the answer
    
    // choose pivot randomly
    int piv = lo + rand() % (hi-lo+1);
    // partition the array
    piv = partition(arr, lo, hi, piv);
    
    // recursively search in the appropriate half
    if(piv==k) return arr[piv];
    else if(piv>k) return quickSelect(arr, k, lo, piv-1);
    else return quickSelect(arr, k, piv+1, hi);
}

// Helper functions
int quickSelect(vector<int>& arr, int k){ 
    if (k < 1 || k > arr.size()) return -1;  // Handle invalid k
    return quickSelect(arr, k-1, 0, arr.size()-1); 
}
void quickSort(vector<int>& arr){ quickSort(arr, 0, arr.size()-1); }
void print(vector<int> arr) { for(auto it: arr) cout<<it<<" "; cout<<"\n"; }

int main()
{
    vector<int> arr = {-3, 7, -8, 5, -2, 1, -9, 5, 0, 6};
    cout << quickSelect(arr, 7) << "\n";
    
    // checking res
    quickSort(arr);
    print(arr);
    return 0;
}