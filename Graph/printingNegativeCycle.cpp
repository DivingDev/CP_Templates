#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
vector<vector<int>> edges;

void solve()
{
    vector<int> dist(n + 1);
    vector<int> parent(n + 1, -1);
    int x;
    for(int i =0 ; i< n;i++) {
        x = -1;
        for(auto e:edges) {
            if(dist[e[0]] < INF && dist[e[1]] > dist[e[0]] + e[2]) {
                dist[e[1]] = max(-INF, dist[e[0]] + e[2]);
                parent[e[1]] = e[0];
                x = e[1];
            }
        }
    }
    
    if (x == -1) {
        cout << "No negative cycle found.";
    } else {
        for (int i = 0; i < n; ++i)
            x = parent[x];

        vector<int> cycle;
        for (int v = x;; v = parent[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "Negative cycle: ";
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    }
}