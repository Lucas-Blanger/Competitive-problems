#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;


int tsp(int n, vector<vector<int>>& dist) {
    int FULL = (1 << n) - 1;
 
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));
 
    dp[1][0] = 0;   // começa no vértice 0, só ele visitado
 
    for (int mask = 1; mask <= FULL; mask++) {
        for (int v = 0; v < n; v++) {
            if (dp[mask][v] == INF) continue;
            if (!(mask & (1 << v))) continue;   // v deve estar em mask
 
            // Tenta ir para cada cidade u ainda não visitada
            for (int u = 0; u < n; u++) {
                if (mask & (1 << u)) continue;          // u já visitado
                if (dist[v][u] == INF) continue;        // aresta inexistente
 
                int newMask = mask | (1 << u);
                dp[newMask][u] = min(dp[newMask][u], dp[mask][v] + dist[v][u]);
            }
        }
    }
 
    int ans = INF;
    for (int v = 1; v < n; v++) {
        if (dp[FULL][v] != INF && dist[v][0] != INF)
            ans = min(ans, dp[FULL][v] + dist[v][0]);
    }
 
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n, 0));


    for(int i = 0; i < n;i++){
        for(int j = 0; j < n; j++){
            cin >> dist[i][j];
        }

    }

    cout << tsp(n, dist) << endl;

   
}