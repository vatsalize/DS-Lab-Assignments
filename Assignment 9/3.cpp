#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x], parent);
}

void unionSet(int a, int b, vector<int>& parent, vector<int>& rnk) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a == b) return;
    if (rnk[a] < rnk[b]) parent[a] = b;
    else if (rnk[b] < rnk[a]) parent[b] = a;
    else { parent[b] = a; rnk[a]++; }
}

int main() {
    int n = 5;
    vector<Edge> edges = {
        {0,1,2},
        {0,3,6},
        {1,2,3},
        {1,3,8},
        {1,4,5},
        {2,4,7},
        {3,4,9}
    };

    cout << "Input (MST):" << endl;
    cout << "Vertices: 0 1 2 3 4" << endl;
    cout << "Edges (u v w):" << endl;
    for (auto &e : edges)
        cout << e.u << " " << e.v << " " << e.w << endl;
    cout << endl;

    // Kruskal
    vector<Edge> eK = edges;
    sort(eK.begin(), eK.end(), [](Edge a, Edge b){ return a.w < b.w; });
    vector<int> parent(n), rnk(n,0);
    for (int i = 0; i < n; ++i) parent[i] = i;

    int costK = 0;
    cout << "Output (Kruskal MST edges):" << endl;
    for (auto &e : eK) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            cout << e.u << " - " << e.v << " (w=" << e.w << ")" << endl;
            costK += e.w;
            unionSet(e.u, e.v, parent, rnk);
        }
    }
    cout << "Total MST weight (Kruskal): " << costK << endl << endl;

    // Prim
    vector<vector<pair<int,int>>> adj(n);
    for (auto &e : edges) {
        adj[e.u].push_back({e.v, e.w});
        adj[e.v].push_back({e.u, e.w});
    }

    int start = 0;
    vector<int> key(n, INT_MAX), par(n, -1), inMST(n,0);
    key[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (inMST[u]) continue;
        inMST[u] = 1;
        for (auto &p : adj[u]) {
            int v = p.first, w = p.second;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                par[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    int costP = 0;
    cout << "Output (Prim MST edges):" << endl;
    for (int v = 0; v < n; ++v) {
        if (par[v] != -1) {
            cout << par[v] << " - " << v << " (w=" << key[v] << ")" << endl;
            costP += key[v];
        }
    }
    cout << "Total MST weight (Prim): " << costP << endl;

    return 0;
}
