#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
const int INF = 1e9;

int d[MAXN][MAXN];

void floyd() {
    for (int k = 1; k <= 100; k++) {
        for (int i = 1; i <= 100; i++) {
            for (int j = 1; j <= 100; j++) {

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

    int a, b;
    int tc = 1;

    while (true) {

        // inicialização
        for (int i = 1; i <= 100; i++) {
            for (int j = 1; j <= 100; j++) {
                if (i == j) d[i][j] = 0;
                else d[i][j] = INF;
            }
        }

        set<int> nodes;

        cin >> a >> b;

        // fim total da entrada
        if (a == 0 && b == 0)
            break;

        // primeiro par
        d[a][b] = 1;
        nodes.insert(a);
        nodes.insert(b);

        // restante do caso
        while (cin >> a >> b) {

            if (a == 0 && b == 0)
                break;

            d[a][b] = 1;

            nodes.insert(a);
            nodes.insert(b);
        }

        floyd();

        double sum = 0;
        int cnt = 0;

        for (int i : nodes) {
            for (int j : nodes) {

                if (i == j)
                    continue;

                sum += d[i][j];
                cnt++;
            }
        }

        cout << fixed << setprecision(3);

        cout << "Case " << tc++ << ": average length between pages = " << (sum / cnt) << " clicks\n";
    }
}