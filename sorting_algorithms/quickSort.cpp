#include <bits/stdc++.h>
using namespace std;

// Quick Sort: O(n^2) worst case 
// O(nlogn) average

// O(1) space
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

// O(nlogn)
void quickSort(vector<int>& arr, int lo, int hi){
    if(lo>=hi) return;
    
    // choose a pivot
    // int piv = hi;
    int pivInd = lo + rand() % (hi - lo + 1);  // Randomized pivot selection
    
    // partition the array
    pivInd = partition(arr, lo, hi, pivInd);
    
    // recursively sort the two halves
    quickSort(arr, lo, pivInd-1);
    quickSort(arr, pivInd+1, hi);
}

void quickSort(vector<int>& arr){ quickSort(arr, 0, arr.size()-1); }
void print(vector<int> arr) { for(auto it: arr) cout<<it<<" "; cout<<"\n"; }

int main()
{
    vector<int> arr{3, 2, 4, 10, 5};
    quickSort(arr);
    print(arr);
    return 0;
}