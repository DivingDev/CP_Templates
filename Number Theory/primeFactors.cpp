#include <bits/stdc++.h>
using namespace std;

vector<long long> primes;
// precompute the primes and store it in prime vector


vector<long long> trial_division(long long n) {
    vector<long long> factorization;
    for (long long d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}