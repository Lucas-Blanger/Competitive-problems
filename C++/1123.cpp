#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, int> pli;
const long long INF = 1e18;

// adj[u] = {custo, vizinho}
vector<pli> adj[100005];

vector<long long> dijkstra(int src, int n) {
    vector<long long> dist(n + 1, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue; // lazy delete

        for (auto [w, v] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n,m,c,k;
    while(true){
        cin >> n >> m >> c >> k;
        if(n == 0 && m == 0 && c == 0 && k == 0) break;
        for(int i = 0; i < n; i++) adj[i].clear();
        while (m--) {
            int u, v; long long w;
            cin >> u >> v >> w;
            if (u < c && v < c) {
                if (v == u + 1) adj[u].push_back({w, v});
                if (u == v + 1) adj[v].push_back({w, u});
            } else if (u < c) {
                if (v == u + 1) adj[u].push_back({w, v});
                adj[v].push_back({w, u}); // v é livre
            } else if (v < c) {
                if (u == v + 1) adj[v].push_back({w, u});
                adj[u].push_back({w, v});
            } else {
                // nenhum está na rota
                adj[u].push_back({w, v});
                adj[v].push_back({w, u});
            }
        }

        auto dist = dijkstra(k, n);

        if (dist[c-1] == INF) cout << -1 << "\n";
        else cout << dist[c-1] << "\n";

    }

   
}
