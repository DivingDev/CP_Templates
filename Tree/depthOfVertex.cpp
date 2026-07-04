// Depth of a child is one more than the depth of its parent.

void dfs(int node, int parent) {

    for(int child: adj[node]) {
        if(child == parent) continue;

        depth[child] = 1 + depth[node];

        dfs(child,node);
    }
}