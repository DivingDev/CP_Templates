#include <bits/stdc++.h>
using namespace std;

int timer = 1;
void BridgeInGraph(int node, int par, vector<bool> &vis, int tin[], int low[], vector<int> adj[], vector<vector<int>> &bridges) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    for (auto v : adj[node]) {
        if (v == par)
            continue;

        if (vis[v]) {
            low[node] = min(low[node], low[v]);
        } else {
            BridgeInGraph(v, node, vis, tin, low, adj, bridges);
            low[node] = min(low[node], low[v]);

            if (low[v] > tin[node]) {
                bridges.push_back({node, v});
            }
        }
    }
}