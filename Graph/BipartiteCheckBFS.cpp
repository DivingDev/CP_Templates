#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int src, int n, vector<int> adj[]) {
    queue<int> q;
    vector<int> color(n,-1);
    color[src] = 0;
    q.push(src);

    while(!q.empty()) {
        auto node = q.front();
        q.pop();

        for(auto v:adj[node]) {
            if(color[v] == -1) {
                color[v] = !color[node];
                q.push(v);
            }
            else if(color[v] == color[node]) return false;
        }
    }
    return true;
}