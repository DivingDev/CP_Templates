#include <bits/stdc++.h>
using namespace std;

// T.C. = O(N^2)

int LIS(vector<int> &nums) {
    int n = nums.size();
    vector<int>dp(n,1);          // dp[i] = length of longest increasing subsequence that ends in the element at index i
    for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(nums[i] > nums[j]) dp[i] = max(dp[i],dp[j]+1);
        }
    }
    return *max_element(dp.begin(),dp.end());
}

// best soln 
// T.C. O(n*logn)
int lis(vector<int> &nums) {
    vector<int>lis;
    for(auto it:nums) {
        if(lis.empty() || lis.back() < it) {
            lis.push_back(it);
        }
        else {
            auto ptr = lower_bound(lis.begin(),lis.end(),it);
            *ptr = it;
        }
    }
    return lis.size();
}