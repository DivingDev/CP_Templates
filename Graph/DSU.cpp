#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, size, rank;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        rank.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u != ulp_v) {
            if (size[ulp_u] < size[ulp_v])
                swap(ulp_u, ulp_v);
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u != ulp_v) {
            if(rank[ulp_u] < rank[ulp_v]) 
                swap(ulp_u,ulp_v);
            parent[ulp_v] = ulp_u;
            if(rank[ulp_u] == rank[ulp_v]) rank[ulp_u]++;
        }
    }
};
