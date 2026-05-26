#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

struct Edge {
    int to;
    int peso;
};

void bfs(int origem, vector<vector<Edge>>& grafo, int n, ll K) {
    
    queue<int> fila;
    vector<bool> visitado(n + 1, false);

    vector<ll> dist(n + 1, 0);

    vector<ll> soma(n + 1, 0);

    vector<ll> maior(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (auto e : grafo[i]) {
            maior[i] = max(maior[i], (ll)e.peso);
        }
    }

    fila.push(origem);
    visitado[origem] = true;

    ll r = 0;

    while (!fila.empty()) {

        int atual = fila.front();
        fila.pop();

        if (dist[atual] <= K) {

            ll pontos =
                soma[atual] +
                (K - dist[atual]) * maior[atual];

            r = max(r, pontos);
        }

        for (auto e : grafo[atual]) {

            int vizinho = e.to;

            if (!visitado[vizinho]) {

                visitado[vizinho] = true;

                dist[vizinho] = dist[atual] + 1;

                soma[vizinho] =
                    soma[atual] + e.peso;

                fila.push(vizinho);
            }
        }
    }

    cout << r;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<Edge>> grafo(n + 1);

    for (int i = 0; i < n - 1; i++) {

        int u, v, w;
        cin >> u >> v >> w;

        grafo[u].push_back({v, w});
        grafo[v].push_back({u, w});
    }

    ll k;
    cin >> k;

    int X;
    cin >> X;

    bfs(X, grafo, n, k);


}