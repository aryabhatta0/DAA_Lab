#include <bits/stdc++.h>
using namespace std;

// Linear Probing
class hashTable {
private:
    int size;
    vector<int> arr;

    int hashIndex(int key){
        return key % 5;
    }

public:
    hashTable(int sz){
        size = sz;
        arr.resize(sz, -1);
    }

    void insert(int key){
        int ind = hashIndex(key);
        // Linear probing
        while(arr[ind] != -1 && arr[ind] != -2){
            ind = (ind + 1) % size;
            if(ind == 0) break;
        }

        // space bacha nahi toh, kya karenge?
        arr[ind] = key;
    }

    bool search(int key){
        int ind = hashIndex(key);
        while(arr[ind] != -1){
            if(arr[ind] == key) return true;

            ind = (ind + 1) % size;
            if(ind == 0) break;
        }
        return false;
    }

    bool remove(int key){
        int ind = hashIndex(key);
        while(arr[ind] != -1){
            if(arr[ind] == key){
                arr[ind] = -2;
                return true;
            }

            ind = (ind + 1) % size;
            if(ind == 0) break;
        }
        return false;
    }
};

// CHAINING
class hashTable_chain {
private:
    int size;
    vector<vector<int>> arr;

    int hashIndex(int key){
        return key % 5;
    }

public:
    hashTable_chain(int sz){
        size = sz;
        arr.resize(sz);
    }

    void insert(int key){
        int ind = hashIndex(key);
        // chaining
        arr[ind].push_back(key);
    }

    bool search(int key){
        int ind = hashIndex(key);
        auto it = find(arr[ind].begin(), arr[ind].end(), key);
        if(it != arr[ind].end()) return true;
        else return false;
    }

    bool remove(int key){
        int ind = hashIndex(key);
        auto it = find(arr[ind].begin(), arr[ind].end(), key);
        if(it != arr[ind].end()) {
            arr[ind].erase(it);
            return true;
        }
        return false;
    }
};

int main(){
    hashTable_chain ht(5);
    ht.insert(5);
    ht.insert(12);
    ht.insert(11);
    ht.insert(10);
    ht.insert(23);

    cout << (ht.search(12) ? "Found" : "Not Found") << "\n";
    cout << (ht.search(15) ? "Found" : "Not Found") << "\n";

    cout << (ht.remove(11) ? "Removed" : "Doesn't exist. Couldn't remove.") << "\n";
    cout << (ht.search(11) ? "Found" : "Not Found") << "\n";

    ht.insert(20);
    cout << (ht.search(20) ? "Found" : "Not Found") << "\n";
}
