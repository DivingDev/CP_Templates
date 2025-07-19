#include <bits/stdc++.h>
using namespace std;

// T.C. --> O(N^2)
// S.C. --> O(1)

// push the max to the last by adjacent swaps
void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            if(arr[j] > arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}