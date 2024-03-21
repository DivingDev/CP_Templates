#include <bits/stdc++.h>
using namespace std;

double powerExponentiation(int a, int x) {
    double ans = 1;
    int temp = x;
    x = x < 0 ? x*-1:x;
    while(x>0) {
        if(x&1) {
            ans = ans * a;
            x = x - 1;
        }
        else {
            a = a * a;
            x = x/2;
        }
    }
    if(temp < 0) ans = 1.0/ans;
    return ans;
}