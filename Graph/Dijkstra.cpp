// O((N+E)*log(N))
// Single source sohortest path
void dijkstra(int n, int s, vector<pii> adj[])
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    vector<int> dist(n, INF);
    dist[s] = 0;
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edW = it.second;
            if (dist[adjNode] > dist[node] + edW)
            {
                dist[adjNode] = dist[node] + edW;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
}