#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, pair<int,int>> pli;

const long long INF = 1e18;
vector<pair<int,int>> adj[100005]; 

long long dist[100005][2];

int main(){
    int c, v;
    cin >> c >> v;

    for(int i = 0; i < v; i++){
        int c1, c2, g;
        cin >> c1 >> c2 >> g;
        adj[c1].push_back({g,c2});
        adj[c2].push_back({g,c1});
    }

    for(int i = 1; i <= c; i++){
        dist[i][0] = dist[i][1] = INF;
    }

    priority_queue<pli, vector<pli>, greater<pli>> pq;

    dist[1][0] = 0;
    pq.push({0, {1, 0}});

    while(!pq.empty()){
        auto [d, info] = pq.top(); pq.pop();
        auto [u, p] = info;

        if(d > dist[u][p]) continue;

        for(auto [w, v] : adj[u]){
            int np = (p + 1) % 2;

            if(dist[u][p] + w < dist[v][np]){
                dist[v][np] = dist[u][p] + w;
                pq.push({dist[v][np], {v, np}});
            }
        }
    }

    if(dist[c][0] == INF) cout << -1 << "\n";
    else cout << dist[c][0] << "\n";
}