#include <bits/stdc++.h>
using namespace std;

/*
Prim’s algorithm resembles Dijkstra’s algorithm. The difference is that 
Dijkstra’s algorithm always selects an edge whose distance from the starting node is minimum,
but Prim’s algorithm simply selects the minimum weight edge that adds a new node to the tree

T.C. = O(n + m*logm)
*/

vector<vector<int>> MST(vector<pair<int,int>> adj[], int n) {
    priority_queue<pair<int,pair<int,int>>>pq;
    vector<bool> vis(n,0);
    
    int sum = 0;
    pq.push({0,{0,-1}});     // {wt,{node,par}}
    
    vector<vector<int>> mst;

    while(!pq.empty()) {
        int wt = -pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;

        if(vis[node]) continue;
        vis[node] = 1;

        sum += wt;  // calculating sum of edges of MST

        // storing edges of MST
        if(par != -1) {
            mst.push_back({par,node});
        }

        for(auto it:adj[node]) {
            int adjNode = it.first;
            int edW = it.second;

            if(!vis[adjNode]) {
                pq.push({-edW,{adjNode,node}});
            }
        }
    }

    return mst;
}

