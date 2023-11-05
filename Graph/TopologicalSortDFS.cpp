// O(N+E)

void TopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            TopoSort(it, vis, st, adj);
        }
    }
    st.push(node);
}