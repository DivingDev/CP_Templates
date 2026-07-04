// Number of vertices in a node subTree is the sum of number of nodes 
// in its children's subtree increased by one.

void dfs(int node, int parent) {

    for(int child: adj[node]) {
        
        if(child != parent) {
            dfs(child,node);
            sub[node] += sub[child];
        }

        sub[node] += 1;
    }
}