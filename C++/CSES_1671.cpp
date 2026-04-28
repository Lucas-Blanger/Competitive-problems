#include <bits/stdc++.h>


using namespace std;

typedef pair<long long, int> pli;
const long long INF = 1e18;

vector<pli> adj[100005];

vector<long long> dijkstra(int src, int n) {
    vector<long long> dist(n + 1, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

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
    int n, m; 
    cin >> n >> m;

    while (m--) {
        int u, v; long long w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v}); // grafo dirigido
    }

    auto dist = dijkstra(1, n);

    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    cout << "\n";
}