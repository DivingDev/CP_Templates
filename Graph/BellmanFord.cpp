// sortest distance of all vertices from the source vertex
// Detects negative cycle
// O(V*E)
vector<int> BellmanFord(int n, int s, vector<vector<int>> &edges)
{
    vector<int> dist(n, INF);
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != INF && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    // Nth relaxation
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != INF && dist[u] + wt < dist[v])
        {
            return {-1};
        }
    }
    return dist;
}