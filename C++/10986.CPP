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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int c;
    cin >> c;
    int caso = 0;
    while(c--){
        int n,m,s,t;
        cin >> n >> m >> s >> t;
        caso++;
        for(int i = 0; i < n; i++) adj[i].clear();
        for(int i = 0; i < m;i++){
            int u,v,w;
            cin >> u >> v >> w;
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});

        }

        auto dist = dijkstra(s, n);

        if (dist[t] == INF) cout << "Case #" << caso << ": unreachable"  << "\n";
        else cout << "Case #" << caso << ": " << dist[t] << "\n";

    }

}