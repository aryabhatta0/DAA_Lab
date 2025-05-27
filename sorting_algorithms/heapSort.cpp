#include <bits/stdc++.h>
using namespace std;

/** HEAP:
 * Implementation of a pq
 * Array visualized as Binary Tree
 * 
 * A max heap represented array need not be sorted.
 * Children: arr[2i], arr[2i+1]     or      arr[2i+1], arr[2i+2]
 * 
 * MAX HEAP: value of par >= it's children
 * hence root at top
 */

// correct a single violation of t/he heap property in a subtree rooted at ind
// assumption: tree rooted at left and right childs are max-heaps
void maxHeapify(vector<int> &arr, int n, int ind){
    int maxiNode=ind, maxi=arr[ind];
    if(2*ind+1<n && arr[2*ind+1] > maxi) {
        maxi=arr[2*ind+1];
        maxiNode=2*ind+1;
    }
    if(2*ind+2<n && arr[2*ind+2] > maxi) {
        maxi=arr[2*ind+2];
        maxiNode=2*ind+2;
    }

    if(maxiNode!=ind){
        swap(arr[ind], arr[maxiNode]);
        maxHeapify(arr, n, maxiNode);
    }
}

// rearrange the arr representing a binary tree to follow max heap property
void buildHeap(vector<int> &arr, int n){
    // building from leaf
    for(int i=n/2-1; i>=0; i--){
        maxHeapify(arr, n, i);
    }
}

void heapSort(vector<int> &arr){
    int n=arr.size();

    buildHeap(arr, n);      // O(n)
    
    while(n>1){     // while the size of maxHeap is 1
        swap(arr[0], arr[n-1]); // put max elem at the end of final array (inplace)
        n--;
        maxHeapify(arr, n, 0);  // since only root violate the maxHeap prop, childrens are maxHeap
    }
}

void print(vector<int> &arr){ cout<<"Array: "; for(auto it: arr) cout<<it<<" "; cout<<"\n"; }

int main()
{
    vector<int> arr{ 12, 11, 13, 5, 6, 7 };
    heapSort(arr);
    print(arr);
    return 0;
}