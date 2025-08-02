#include <bits/stdc++.h>

using namespace std;

struct Requisicao {
    int inicio, fim;
};

bool comp(const Requisicao &a, const Requisicao &b) {
    return a.fim < b.fim;
}

int buscaUltimo(const vector<Requisicao> &req, int indice) {
    int baixo = 0, alto = indice - 1;
    int res = -1;
    int inicio = req[indice].inicio;
    while (baixo <= alto) {
        int meio = (baixo + alto) / 2;
        if (req[meio].fim <= inicio) {
            res = meio;
            baixo = meio + 1;
        } else {
            alto = meio - 1;
        }
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<Requisicao> req(N);

    for (int i = 0; i < N; i++) {
        cin >> req[i].inicio >> req[i].fim;
    }

    sort(req.begin(), req.end(), comp);

    vector<int> dp(N, 0);

    for (int i = 0; i < N; i++) {
        int duracao = req[i].fim - req[i].inicio;
        int ultimo = buscaUltimo(req, i);
        int valorComAtual = duracao;
        if (ultimo != -1)
            valorComAtual += dp[ultimo];
        dp[i] = max((i > 0 ? dp[i - 1] : 0), valorComAtual);
    }

    cout << dp[N - 1] << "\n";

}
