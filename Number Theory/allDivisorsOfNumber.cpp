#include <bits/stdc++.h>
using namespace std;

// time complexity is O(sqrt(N))

vector<long long> divisors(long long n) {
    vector<long long> divisor;
    for(int i=1;i*i<=n;i++) {
        if(n % i == 0) {
            divisor.push_back(i);
            if(n / i != i) {
                divisor.push_back(n / i);
            }
        }
    }
    return divisor;
}