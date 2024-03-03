#include <bits/stdc++.h>
using namespace std;
//  T.C. = O(2^N) * O(N)
// 2^N to generate and N to print
void printSubset(int i, vector<int> &a, vector<int> &ds, int n) {
    if(i == n) {
        for(auto it:ds) cout<<it<<" ";   // O(N) for printing
        cout<<endl;
        return;
    }
    ds.push_back(a[i]);
    printSubset(i+1,a,ds,n);
    ds.pop_back();
    printSubset(i+1,a,ds,n);
}