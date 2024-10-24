#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int node, bool col, vector<int> &color, vector<int> adj[]) {
    color[node] = col;

    for(auto v:adj[node]) {
        if(color[v] == -1) {
            if(isBipartite(v,!col,color,adj) == false) return false;
        } 
        else if(color[v] == col) return false;
    }
    return true;
}