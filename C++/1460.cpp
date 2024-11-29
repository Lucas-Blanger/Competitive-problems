#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int linhas, colunas;
        cin >> linhas >> colunas;
        if (linhas == 0 && colunas == 0) break;

        vector<vector<int>> alturas(linhas, vector<int>(colunas));
        for (int i = 0; i < linhas; ++i) {
            for (int j = 0; j < colunas; ++j) {
                cin >> alturas[i][j];
            }
        }

        int consultas;
        cin >> consultas;
        while (consultas--) {
            int minimo, maximo;
            cin >> minimo >> maximo;

            int maiorQuadrado = 0;

            for (int i = 0; i < linhas; ++i) {
                auto inicio = lower_bound(alturas[i].begin(), alturas[i].end(), minimo);
                int colunaInicio = inicio - alturas[i].begin();

                for (int tamanho = maiorQuadrado; tamanho < linhas - i && tamanho < colunas; ++tamanho) {
                    if (i + tamanho >= linhas || colunaInicio + tamanho >= colunas) break;

                    if (alturas[i + tamanho][colunaInicio + tamanho] > maximo) break;

                    maiorQuadrado = tamanho + 1;
                }
            }

            cout << maiorQuadrado << "\n";
        }

        cout << "-\n";
    }

    return 0;
}
