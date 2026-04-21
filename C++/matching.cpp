#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 50005;

int n, m; // tamanho dos lados L e R
vector<int> adj[MAXN]; // adj[u] = vizinhos de u (lado esquerdo)
int matchL[MAXN], matchR[MAXN], dist[MAXN];

bool bfs() {
    queue<int> q;
    for (int u = 1; u <= n; u++) {
        if (matchL[u] == 0) { dist[u] = 0; q.push(u); }
        else dist[u] = INF;
    }
    bool found = false;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            int w = matchR[v];
            if (w == 0) found = true;
            else if (dist[w] == INF) {
                dist[w] = dist[u] + 1;
                q.push(w);
            }
        }
    }
    return found;
}

bool dfs(int u) {
    for (int v : adj[u]) {
        int w = matchR[v];
        if (w == 0 || (dist[w] == dist[u] + 1 && dfs(w))) {
            matchL[u] = v;
            matchR[v] = u;
            return true;
        }
    }
    dist[u] = INF;
    return false;
}

int hopcroftKarp() {
    fill(matchL, matchL + n + 1, 0);
    fill(matchR, matchR + m + 1, 0);
    int matching = 0;
    while (bfs())
        for (int u = 1; u <= n; u++)
            if (matchL[u] == 0 && dfs(u))
                matching++;
    return matching;
}

int main() {
    int edges;
    cin >> n >> m >> edges;
    while (edges--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << hopcroftKarp() << "\n";
}
