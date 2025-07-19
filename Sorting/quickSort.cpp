#include <bits/stdc++.h>
using namespace std;

// T.C. --> O(NlogN)
// S.C. --> O(1)

// pick a pivot and place it in its correct position in sorted array
int f(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    
    while(i < j) {
        while(arr[i] <= arr[pivot] && i <= high) {
            i++;
        }

        while(arr[j] >= arr[pivot] && j >= low) {
            j--;
        }

        if(i < j) swap(arr[i],arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high) {
    if(low < high) {
        int pInd = f(arr, low, high);
        quickSort(arr,low,pInd-1);
        quickSort(arr,pInd+1,high);
    }
}