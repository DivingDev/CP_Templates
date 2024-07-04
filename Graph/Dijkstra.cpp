#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
// O(n + m*logm)  where n is no. of nodes and m is no. of edges
// Single source sohortest path
void dijkstra(int n, int s, vector<pii> adj[])
{
    priority_queue<pii> pq; //{dist,node}
    vector<int> dist(n + 1, 1e9);
    vector<bool> vis(n + 1, 0);
    dist[s] = 0;
    pq.push({0, s});
    vector<int> parent(n + 1, -1); //  only if want to print path
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (vis[u])
            continue;
        vis[u] = 1;

        for (auto it : adj[u])
        {
            int edW = it.second;
            int v = it.first;
            if (dist[v] > dist[u] + edW)
            {
                dist[v] = dist[u] + edW;
                pq.push({-dist[v], v});
                // updating for path
                parent[v] = u;
            }
        }
    }
}

// function takes starting vertex s
// path to any vertex t can be restored in following way
vector<int> restore_path(int s, int t, vector<int> const &p)
{
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}