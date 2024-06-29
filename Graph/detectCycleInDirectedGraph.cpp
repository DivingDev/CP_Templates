#include <bits/stdc++.h>
using namespace std;

// T.C. = O(V+E);

vector<bool> vis, pathVis;
vector<vector<int>> adj;

bool dfs(int node)
{
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto v : adj[node])
    {
        if (!vis[v])
        {
            if (dfs(v))
                return 1;
        }
        else if (pathVis[v])
            return 1;
    }
    pathVis[node] = 0;
    return 0;
}

bool isCycle() {
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            if(dfs(i)) return 1;
        }
    }
    return 0;
}
