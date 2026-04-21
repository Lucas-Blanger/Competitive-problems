#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 1005;

int n, m;
vector<int> adj[MAXN];
int matchL[MAXN], matchR[MAXN], dist[MAXN];

bool bfs() {
    queue<int> q;
    for (int u = 1; u <= n; u++) {
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
    fill(matchL, matchL + n + 1, 0);
    fill(matchR, matchR + m + 1, 0);

    int matching = 0;

    while (bfs()) {
        for (int u = 1; u <= n; u++) {
            if (matchL[u] == 0 && dfs(u))
                matching++;
        }
    }
    return matching;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) adj[i].clear();

    while (k--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int res = hopcroftKarp();

    cout << res << "\n";

    for (int u = 1; u <= n; u++) {
        if (matchL[u] != 0) {
            cout << u << " " << matchL[u] << "\n";
        }
    }
}