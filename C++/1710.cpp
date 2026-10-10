
#include <bits/stdc++.h>
using namespace std;

struct Plano {
    long long A, B, C, D;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<Plano> planos(M);

    for (int i = 0; i < M; i++) {
        cin >> planos[i].A
            >> planos[i].B
            >> planos[i].C
            >> planos[i].D;
    }

    map<string, int> regioes;
    int maior = 0;

    for (int i = 0; i < N; i++) {
        long long x, y, z;
        cin >> x >> y >> z;

        string assinatura;

        for (const auto& p : planos) {
            long long valor =
                p.A * x + p.B * y + p.C * z - p.D;

            assinatura += (valor > 0 ? '1' : '0');
        }

        maior = max(maior, ++regioes[assinatura]);
    }

    cout << maior << '\n';

}
