#include <bits/stdc++.h>
using namespace std;

// T.C. --> O(N^2) --- All three types
// S.C. --> O(1)

// select minimum
void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for(int i = 0; i <= n-2; i++) {
        int mini = i;
        for(int j = i; j <= n-1; j++) {
            if(arr[mini] > arr[j]) mini = j;
        }
        swap(arr[mini], arr[i]);
    }
}