#include <bits/stdc++.h>
using namespace std;

// Time complexity = O(min(r,n-r))
// Space Complexity = O(1);

int nCr(int n, int r) {
    r = min(r,n-r);
    int ans = 1;
    
    for(int i=0;i<r;i++) {
        ans *= (n-i);
        ans /= (i+1);
    }
    return ans;
}