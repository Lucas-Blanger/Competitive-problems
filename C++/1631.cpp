#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Ponto {
    int x, y;
};

double produtoVetorial(Ponto a, Ponto b, Ponto c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double distancia(Ponto a, Ponto b, Ponto p) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    double numerador = abs(dx * (a.y - p.y) - (a.x - p.x) * dy);
    double denominador = sqrt(dx * dx + dy * dy);
    return numerador / denominador;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<Ponto> cerejas(N);
        for (int i = 0; i < N; ++i) {
            cin >> cerejas[i].x >> cerejas[i].y;
        }

        double menor_dif = 1e9;

        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                double soma_esq = 0.0, soma_dir = 0.0;
                for (int k = 0; k < N; ++k) {
                    if (k == i || k == j) continue;

                    double orient = produtoVetorial(cerejas[i], cerejas[j], cerejas[k]);
                    if (orient == 0.0) continue; 

                    double dist = distancia(cerejas[i], cerejas[j], cerejas[k]);
                    if (orient > 0)
                        soma_esq += dist;
                    else
                        soma_dir += dist;
                }

                double diferenca = abs(soma_esq - soma_dir);
                menor_dif = min(menor_dif, diferenca);
            }
        }

        cout << fixed << setprecision(3) << menor_dif << endl;
    }


}
