#include <bits/stdc++.h>
using namespace std;

/* Merge Sort:
O(nlogn)
Recursively sort the two halves, and merge them!
*/

// Suggested Optimization: Creating a temp vec in every call to merge(), instead we could pass a single temp(n) arr to func to reduce memory allocations

// merge [l,mid] & [mid+1, r]
// O(n) space
void merge(vector<int>& arr, int l, int mid, int r){
    int i=l, j=mid+1;
    
    vector<int> temp(r-l+1);
    
    int k=0;
    while(i<=mid && j<=r){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            k++; i++;
        } else {
            temp[k]=arr[j];
            k++; j++;
        }
    }
    
    // copy remaining elements
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=r){
        temp[k++]=arr[j++];
    }
    
    // update arr
    k=0;
    for(int i=l; i<=r; i++){
        arr[i]=temp[k];
        k++;
    }
    
}

// O(nlogn)
// We divide the array in 2 halfs here
void mergeSort(vector<int>& arr, int l, int r){
    if(l<r){
        int mid= l + (r-l)/2;
        
        // recursively sort the 2 halves
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        
        // merge the sorted halves
        merge(arr, l, mid, r);
    }
}

void mergeSort(vector<int>& arr){
    mergeSort(arr, 0, arr.size()-1);
}


void print(vector<int> arr){
    for(auto it: arr) cout<<it<<" "; cout<<"\n";
}

int main()
{
    vector<int> arr{3, 2, 4, 10, 5};
    // vector<int> arr{3, 4, 10, 5, 2};
    mergeSort(arr);
    print(arr);

    return 0;
}