void dfs(int node, int parent) {
    // before entering DFS
    for(int child: adj[node]) {
        if(child != parent) {
            // before entering dfs for child
            dfs(child,node);
            // after exiting dfs for child
        }
    }
    // after exiting DFS
}