#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    vector<pair<int,int>> edges = {
        {0,1}, {0,2}, {1,3}, {2,3}, {1,4}, {3,4}
    };

    vector<vector<int>> adj(n);
    for (auto &e : edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    cout << "Input (BFS):" << endl;
    cout << "Vertices: 0 1 2 3 4" << endl;
    cout << "Edges:" << endl;
    for (auto &e : edges)
        cout << e.first << " -- " << e.second << endl;
    cout << endl;

    int start = 0;
    vector<int> vis(n, 0);
    queue<int> q;
    q.push(start);
    vis[start] = 1;

    cout << "Output (BFS order from " << start << "): ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    cout << endl;
    return 0;
}
