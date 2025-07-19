#include <bits/stdc++.h>
using namespace std;

// T.C. --> O(N^2), best O(N), Avg O(N^2)
// S.C. --> O(1)

// takes an element 
// and place it in its correct position
void insertionSort(vector<int> &arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]) {
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}