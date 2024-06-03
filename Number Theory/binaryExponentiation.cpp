#include <bits/stdc++.h>
using namespace std;

// T.C. = O(long n) where n is exponent

int binexp(int a, int b)
{
    a %= mod;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}