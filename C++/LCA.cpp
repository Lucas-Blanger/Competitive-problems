#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int LOG = 11; // 2^10 > 1000

vector<int> adj[MAXN];
int anc[MAXN][LOG];
int depth[MAXN];
bool hasParent[MAXN];

void dfs(int v, int p) {
    anc[v][0] = p;

    for (int k = 1; k < LOG; k++) {
        anc[v][k] = anc[anc[v][k - 1]][k - 1];
    }

    for (int u : adj[v]) {
        if (u == p) continue;

        depth[u] = depth[v] + 1;
        dfs(u, v);
    }
}

int lca(int u, int v) {

    if (depth[u] < depth[v])
        swap(u, v);

    int diff = depth[u] - depth[v];

    // sobe u
    for (int k = 0; k < LOG; k++) {
        if ((diff >> k) & 1) {
            u = anc[u][k];
        }
    }

    if (u == v) return u;

    for (int k = LOG - 1; k >= 0; k--) {

        if (anc[u][k] != anc[v][k]) {
            u = anc[u][k];
            v = anc[v][k];
        }
    }

    return anc[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {

        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            adj[i].clear();
            hasParent[i] = false;

            for (int j = 0; j < LOG; j++) {
                anc[i][j] = 0;
            }
        }

        for (int i = 1; i <= N; i++) {

            int M;
            cin >> M;

            while (M--) {
                int child;
                cin >> child;

                adj[i].push_back(child);
                adj[child].push_back(i);

                hasParent[child] = true;
            }
        }

        int root = 1;

        for (int i = 1; i <= N; i++) {
            if (!hasParent[i]) {
                root = i;
                break;
            }
        }

        depth[root] = 0;
        dfs(root, 0);

        int Q;
        cin >> Q;

        cout << "Case " << tc << ":\n";

        while (Q--) {

            int u, v;
            cin >> u >> v;

            cout << lca(u, v) << "\n";
        }
    }


}