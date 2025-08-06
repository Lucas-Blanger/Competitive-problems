#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct Aresta {
    int destino, tempo;
};

int main() {
    int C, E;
    while (cin >> C >> E, C || E) {
        vector<vector<Aresta>> grafo(C + 1); 

  
        for (int i = 0; i < E; i++) {
            int u, v, t;
            cin >> u >> v >> t;
            grafo[u].push_back({v, t});
            grafo[v].push_back({u, t});
        }

        int origem;
        cin >> origem;

        vector<int> dist(C + 1, INT_MAX);
        vector<int> pai(C + 1, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> fila;

        dist[origem] = 0;
        fila.push({0, origem});

        while (!fila.empty()) {
            int d = fila.top().first;
            int u = fila.top().second;
            fila.pop();

            if (d > dist[u]) continue;

            for (auto [v, t] : grafo[u]) {
                if (dist[v] > dist[u] + t) {
                    dist[v] = dist[u] + t;
                    pai[v] = u;
                    fila.push({dist[v], v});
                }
            }
        }

        vector<int> caminho;
        for (int v = 1; v != -1; v = pai[v]) {
            caminho.push_back(v);
        }
        reverse(caminho.begin(), caminho.end());

        int tempo = dist[1];
        if (tempo <= 120) {
            cout << "Will not be late. Travel time - " << tempo << " - best way - ";
        } else {
            cout << "It will be " << (tempo - 120) << " minutes late. Travel time - " << tempo << " - best way - ";
        }

        for (int i = 0; i < caminho.size(); i++) {
            if (i > 0) cout << " ";
            cout << caminho[i];
        }
        cout << endl;
    }


}
