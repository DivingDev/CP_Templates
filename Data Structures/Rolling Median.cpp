#include <bits/stdc++.h>
using namespace std;

#define sz(a) a.size()
struct MiddleElement {
    multiset<int> left, right;
    int sizeLeft;
    long long sum = 0;
    
    MiddleElement(int k) {
        sizeLeft = k;
    }
    void balance() {
        while(sz(left) < sizeLeft) {
            sum += *right.begin();
            left.insert(*right.begin());
            right.erase(right.begin());
        }
        while(sz(left) > sizeLeft) {
            sum -= *left.rbegin();
            right.insert(*left.rbegin());
            left.erase(left.find(*left.rbegin()));
        }
    }
    void insert(int x) {
        if(x < *left.rbegin()) left.insert(x), sum += x;
        else right.insert(x);
        balance();
    }
    void erase(int x) {
        auto it = right.find(x);
        if(it != right.end()) right.erase(it);
        else left.erase(left.find(x)), sum -= x;
        balance();
    }
};