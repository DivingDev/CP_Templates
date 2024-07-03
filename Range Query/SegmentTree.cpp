#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int arr[N];

class SGTree
{
    vector<int> seg;

public:
    SGTree(int n)
    {
        seg.resize(4 * n);
    }

    int operation(int &left_node, int &right_node) // may change
    {
        return min(left_node, right_node);
    }

    void build(int idx, int low, int high)
    {
        if (low == high)
        {
            seg[idx] = arr[low]; // may change
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * idx + 1, low, mid);
        build(2 * idx + 2, mid + 1, high);
        seg[idx] = operation(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    void update(int idx, int low, int high, int i, int val) // naver change this
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, val);
        else
            update(2 * idx + 2, mid + 1, high, i, val);
        seg[idx] = operation(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int idx, int low, int high, int l, int r)
    {
        if (high < l || r < low)
        {
            return 1e10; // may change
        }
        if (l <= low && high <= r)
        {
            return seg[idx];
        }
        int mid = low + (high - low) / 2;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return operation(left, right);
    }
};