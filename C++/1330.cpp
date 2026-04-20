#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
const int INF = 1e9;

vector<int> adj[MAXN];
int matchL[MAXN], matchR[MAXN], dist[MAXN];

int nL, nR; // tamanhos dos lados

bool bfs() {
    queue<int> q;
    for (int u = 1; u <= nL; u++) {
        if (matchL[u] == 0) {
            dist[u] = 0;
            q.push(u);
        } else dist[u] = INF;
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
    fill(matchL, matchL + nL + 1, 0);
    fill(matchR, matchR + nR + 1, 0);

    int matching = 0;

    while (bfs()) {
        for (int u = 1; u <= nL; u++) {
            if (matchL[u] == 0 && dfs(u))
                matching++;
        }
    }
    return matching;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;

    while (cin >> N >> M && (N || M)) {
        int K;
        cin >> K;

        bool blocked[105][105] = {};
        int idL[105][105] = {}, idR[105][105] = {};

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            blocked[x][y] = true;
        }

        // limpar grafo
        for (int i = 0; i < MAXN; i++) adj[i].clear();

        nL = nR = 0;

        // dividir em bipartido
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (blocked[i][j]) continue;

                if ((i + j) % 2 == 0)
                    idL[i][j] = ++nL;
                else
                    idR[i][j] = ++nR;
            }
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        // construir arestas
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (blocked[i][j]) continue;

                if ((i + j) % 2 == 0) {
                    int u = idL[i][j];

                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        if (ni >= 1 && ni <= N && nj >= 1 && nj <= M && !blocked[ni][nj]) {
                            int v = idR[ni][nj];
                            if (v != 0)
                                adj[u].push_back(v);
                        }
                    }
                }
            }
        }

        cout << hopcroftKarp() << "\n";
    }


}