#include <bits/stdc++.h>


using namespace std;


typedef pair<long long, int> pli;
const long long INF = 1e18;

// adj[u] = {custo, vizinho}
vector<pli> carro[100005];
vector<pli> aviao[100005];

vector<long long> dijkstra(int src, int n, vector<pli> adj[100005]) {
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

    
   int n,m;
    while(cin >> n >> m){

        for(int i = 1; i <= n; i++){
            carro[i].clear();
            aviao[i].clear();
        }

        while(m--){
            int a,b,t,r;
            cin >> a >> b >> t >> r;

            if(t == 0){
                carro[a].push_back({r, b});
            }else{
                aviao[a].push_back({r, b});
            }
        }

        auto car = dijkstra(1, n, carro);
        auto voar = dijkstra(1, n, aviao);

        cout << min(car[n], voar[n]) << "\n";
    }
    


       

}

