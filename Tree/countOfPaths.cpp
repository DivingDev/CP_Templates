// paths(x) denote the number of paths from node 1 to node x. 
// As a base case, paths(1) = 1.

// T.C. = O(V+E)
// S.C. = O(V+E)

void dfs(int node, vector<int> adj[], vector<int> &topo, vector<int> &vis) {
    vis[node] = 1;
    for(auto child: adj[node]) {
        if(!vis[child])
        dfs(child, adj, topo,vis);
    }
    topo.push_back(node);
}

int countPaths(vector<int> adj[], int V, int sr, int dest) {
    vector<int> topo, paths(V,0), vis(V,0);
    dfs(src, adj, topo, vis);
    reverse(begin(topo),end(topo));
    
    paths[src] = 1;
    for(auto u:topo){
        for(auto v:adj[u]) {
            paths[v] += paths[u];
        }
    }
    return paths[dest];
}