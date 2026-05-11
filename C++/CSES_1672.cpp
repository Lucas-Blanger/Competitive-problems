#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MAXN = 505;

long long d[MAXN][MAXN];
int n, m, q;

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                if (d[i][k] == INF || d[k][j] == INF)
                    continue;

                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    // inicialização
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }

    // leitura das arestas
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;

        cin >> a >> b >> c;

        d[a][b] = min(d[a][b], c);
        d[b][a] = min(d[b][a], c);
    }

    floyd();

    while (q--) {
        int a, b;
        cin >> a >> b;

        if (d[a][b] == INF)
            cout << -1 << "\n";
        else
            cout << d[a][b] << "\n";
    }
}