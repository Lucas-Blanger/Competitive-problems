#include <bits/stdc++.h>
using namespace std;

const int INF = -1;

// Retorna vetor de distâncias a partir de 'start'
// dist[i] = menor número de arestas até o vértice i
// dist[i] = -1 se não alcançável
vector<int> bfs(vector<vector<int>>& adj, int start) {
    int N = adj.size();
    vector<int> dist(N, INF);
    queue<int> fila;

    dist[start] = 0;
    fila.push(start);

    while (!fila.empty()) {
        int v = fila.front(); fila.pop();

        for (int viz : adj[v]) {
            if (dist[viz] == INF) {       // não visitado
                dist[viz] = dist[v] + 1;
                fila.push(viz);
            }
        }
    }
    return dist;
}

// Reconstruir o caminho mínimo até 'end'
vector<int> caminho(vector<vector<int>>& adj, int start, int end) {
    int N = adj.size();
    vector<int> dist(N, INF), pai(N, -1);
    queue<int> fila;

    dist[start] = 0;
    fila.push(start);

    while (!fila.empty()) {
        int v = fila.front(); fila.pop();
        for (int viz : adj[v]) {
            if (dist[viz] == INF) {
                dist[viz] = dist[v] + 1;
                pai[viz] = v;             // guarda de onde veio
                fila.push(viz);
            }
        }
    }

    // Reconstrói o caminho de end até start
    if (dist[end] == INF) return {}; // sem caminho

    vector<int> path;
    for (int v = end; v != -1; v = pai[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    auto id = [&](int r, int c) { return r * m + c; };

    int start = -1, fim = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') start = id(i, j);
            if (grid[i][j] == 'B') fim   = id(i, j);
        }

    int N = n * m;
    vector<vector<int>> adj(N);

    int dr[] = {-1, 1,  0, 0};   
    int dc[] = { 0, 0, -1, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') continue;
            for (int d = 0; d < 4; d++) {
                int ni = i + dr[d], nj = j + dc[d];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (grid[ni][nj] == '#') continue;
                adj[id(i,j)].push_back(id(ni, nj));
            }
        }
    }

    vector<int> path = caminho(adj, start, fim);

    if (path.empty()) {
        cout << "NO\n";
        return 0;
    }

    string moves = "";
    string dirs = "UDLR";
    for (int i = 0; i + 1 < (int)path.size(); i++) {
        int v = path[i], u = path[i+1];
        int r1 = v / m, c1 = v % m;
        int r2 = u / m, c2 = u % m;
        for (int d = 0; d < 4; d++) {
            if (r1 + dr[d] == r2 && c1 + dc[d] == c2) {
                moves += dirs[d];
                break;
            }
        }
    }

    cout << "YES\n";
    cout << path.size() - 1 << "\n";
    cout << moves << "\n";
}
