#include <bits/stdc++.h>
using namespace std;


const int MAXN = 200005;
const int LOG  = 20; // 2^17 > 10^5

int depth[MAXN];
int anc[MAXN][LOG]; // anc[v][k] = ancestral 2^k níveis acima de v
vector<int> adj[MAXN];

void dfs(int v, int pai, int d) {
    depth[v] = d;
    anc[v][0] = pai;
    for (int k = 1; k < LOG; k++)
        anc[v][k] = anc[anc[v][k-1]][k-1];
    for (int u : adj[v])
        if (u != pai) dfs(u, v, d + 1);
}

int lca(int u, int v) {
    // garante que u seja o mais profundo
    if (depth[u] < depth[v]) swap(u, v);

    // iguala profundidades
    int diff = depth[u] - depth[v];
    for (int k = 0; k < LOG; k++)
        if ((diff >> k) & 1) u = anc[u][k];

    if (u == v) return u;

    // sobe junto até um nível abaixo do LCA
    for (int k = LOG - 1; k >= 0; k--)
        if (anc[u][k] != anc[v][k]) {
            u = anc[u][k];
            v = anc[v][k];
        }

    return anc[u][0];
}

int main() {
    int n, q;
    cin >> n >> q;

    // leitura correta do problema
    for (int i = 2; i <= n; i++) {

        int boss;
        cin >> boss;

        adj[boss].push_back(i);
        adj[i].push_back(boss);
    }

    dfs(1, 0, 0);

    while (q--) {

        int a, b;
        cin >> a >> b;

        cout << lca(a, b) << "\n";
    }
}
