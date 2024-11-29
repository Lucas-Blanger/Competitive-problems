#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    string input;

    while (getline(cin, input)) {
        if (input.empty()) break;

        stringstream ss(input);
        int jogos, vitMaisUma;
        ss >> jogos >> vitMaisUma;

        vector<pair<int, int>> resultados(jogos);

        for (int i = 0; i < jogos; i++) {
            int S, R;
            cin >> S >> R;
            resultados[i] = {S, R};
        }

        sort(resultados.begin(), resultados.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return (a.second - a.first) < (b.second - b.first);
             });

        for (int i = 0; i < jogos; i++) {
            int diferenca = resultados[i].second - resultados[i].first;

            if (diferenca == 0 && vitMaisUma > 0) {
                resultados[i].first++;
                vitMaisUma--;
            } else if (diferenca > 0) {
                if (vitMaisUma >= diferenca + 1) {
                    resultados[i].first += diferenca + 1;
                    vitMaisUma -= (diferenca + 1);
                } else if (vitMaisUma >= diferenca) {
                    resultados[i].first += diferenca;
                    vitMaisUma -= diferenca;
                }
            }
        }

        for (int i = 0; i < jogos; i++) {
            if (resultados[i].first == resultados[i].second && vitMaisUma > 0) {
                resultados[i].first++;
                vitMaisUma--;
            }
        }

        int pontos = 0;
        for (const auto& resultado : resultados) {
            if (resultado.first > resultado.second) {
                pontos += 3;
            } else if (resultado.first == resultado.second) {
                pontos += 1;
            }
        }

        cout << pontos << endl;

        cin.ignore();
    }

    return 0;
}
