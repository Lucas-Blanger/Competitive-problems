#include <bits/stdc++.h>

using namespace std;

const int MAX = 50;

int main() {

    
    int t;
    cin >> t;

    while (t--) {
        int pac;
        cin >> pac;

        vector<int> qt(pac);
        vector<int> peso(pac);

        for (int i = 0; i < pac; i++) {
            cin >> qt[i] >> peso[i];
        }

        vector<int> dp(MAX + 1, 0);
        vector<vector<int>> path(MAX + 1, vector<int>(pac, 0));

        for (int i = 0; i < pac; i++) {
            for (int w = MAX; w >= peso[i]; w--) {
                if (dp[w - peso[i]] + qt[i] > dp[w]) {
                    dp[w] = dp[w - peso[i]] + qt[i];
                    path[w] = path[w - peso[i]];
                    path[w][i] = path[w - peso[i]][i] + 1;
                }
            }
        }

        int maxB = 0, pesoFinal = 0;
        for (int w = 0; w <= MAX; ++w) {
            if (dp[w] > maxB) {
                maxB = dp[w];
                pesoFinal = w;
            }
        }

        int usados = 0;
        for (int i = 0; i < pac; ++i) {
            if (path[pesoFinal][i] > 0) {
                usados++;
            }
        }

        cout << maxB << " brinquedos\n";
        cout << "Peso: " << pesoFinal << " kg\n";
        cout << "sobra(m) " << (pac - usados) << " pacote(s)\n\n";
    }
}
