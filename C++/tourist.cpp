#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Evento {
    int x, t;
};

bool compara(Evento a, Evento b) {
    return a.t < b.t;
}

int calculaEventos(const vector<Evento>& eventos, int v, int inicio) {
    int n = eventos.size();
    vector<int> dp(n, 0);

    for (int i = 0; i < n; ++i) {
        if (abs(eventos[i].x - inicio) <= eventos[i].t * v) {
            dp[i] = 1;
        }

        for (int j = 0; j < i; ++j) {
            if (dp[j] > 0 && abs(eventos[i].x - eventos[j].x) <= (eventos[i].t - eventos[j].t) * v) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n, v;
    cin >> n;

    vector<Evento> eventos(n);
    for (int i = 0; i < n; ++i) {
        cin >> eventos[i].x >> eventos[i].t;
    }
    cin >> v;

    sort(eventos.begin(), eventos.end(), compara);

    int maxEventosInicial = calculaEventos(eventos, v, 0);

    int maxEventosLivre = 0;
    for (int i = 0; i < n; ++i) {
        maxEventosLivre = max(maxEventosLivre, calculaEventos(eventos, v, eventos[i].x));
    }

    cout << maxEventosInicial << " " << maxEventosLivre << "\n";
    return 0;
}
