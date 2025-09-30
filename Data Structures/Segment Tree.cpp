#include <bits/stdc++.h>
using namespace std;

struct node
{
    int sum;
    node()
    {
        sum = 0;
    }
};

node sgt[4 * 1000000];

node merge(node l, node r)
{
    node ans;
    ans.sum = l.sum + r.sum;
    return ans;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        // leaf node
        sgt[id].sum = 0;
        return;
    }

    int mid = l + (r - l) / 2;
    build(2 * id + 1, l, mid);
    build(2 * id + 2, mid + 1, r);
    sgt[id] = merge(sgt[2 * id + 1], sgt[2 * id + 2]);
}

void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        sgt[id].sum += val;
        return;
    }

    int mid = l + (r - l) / 2;
    update(2 * id + 1, l, mid, pos, val);
    update(2 * id + 2, mid + 1, r, pos, val);
    sgt[id] = merge(sgt[2 * id + 1], sgt[2 * id + 2]);
}

node query(int id, int l, int r, int lq, int rq)
{
    // no overlap
    if (lq > r || l > rq)
    {
        return node();
    }

    // complete overlap
    if (lq <= l && r <= rq)
    {
        return sgt[id];
    }

    int mid = l + (r - l) / 2;
    return merge(query(2 * id + 1, l, mid, lq, rq), query(2 * id + 2, mid + 1, r, lq, rq));
}