#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    vector<tuple<int,int,int>> edges = {
        {0,1,2},
        {0,3,6},
        {1,2,3},
        {1,3,8},
        {1,4,5},
        {2,4,7},
        {3,4,9}
    };

    vector<vector<pair<int,int>>> adj(n);
    for (auto &t : edges) {
        int u, v, w;
        tie(u,v,w) = t;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    cout << "Input (Dijkstra):" << endl;
    cout << "Vertices: 0 1 2 3 4" << endl;
    cout << "Edges (u v w):" << endl;
    for (auto &t : edges) {
        int u, v, w;
        tie(u,v,w) = t;
        cout << u << " " << v << " " << w << endl;
    }
    cout << endl;

    int start = 0;
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d != dist[u]) continue;
        for (auto &p : adj[u]) {
            int v = p.first, w = p.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Output (Shortest distances from " << start << "):" << endl;
    for (int i = 0; i < n; ++i)
        cout << "Vertex " << i << " : " << dist[i] << endl;

    return 0;
}
