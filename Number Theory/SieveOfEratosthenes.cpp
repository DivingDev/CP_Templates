#include <bits/stdc++.h>
using namespace std;

// Time Complexity = O(n log log n)
// Space Complexity = O(n)

// replacing n with 1e6 for generalization

vector<bool> is_prime(1e6+1, true);
void SieveOfEratosthenes() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 1e6; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 1e6; j += i)
                is_prime[j] = false;
        }
    }
}