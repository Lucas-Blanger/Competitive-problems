#include <bits/stdc++.h>


using namespace std;

long long prim(int n, vector<vector<pair<int,int>>>& adj, int src = 1) {
    vector<int> dist(n + 1, INT_MAX);
    vector<bool> inMST(n + 1, false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});

    long long custo = 0;
    int visitados = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        custo += d;
        visitados++;

        for (auto& [v, w] : adj[u]) {
            if (!inMST[v] && w < dist[v]) {
                dist[v] = w;
                pq.push({w, v});
            }
        }
    }

    return (visitados == n) ? custo : -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1); 

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); 
        adj[v].push_back({u, w});
    }

    long long resultado = prim(n, adj, 1); 
    
    cout << resultado << "\n";
}