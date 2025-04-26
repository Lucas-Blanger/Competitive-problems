#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

int contarFormas(const string& palavra, const unordered_set<string>& dicionario) {
    int tamanho = palavra.size();
    vector<int> dp(tamanho + 1, 0);
    dp[0] = 1; 

    for (int i = 1; i <= tamanho; ++i) {
        for (int j = max(0, i - 100); j < i; ++j) {
            if (dicionario.count(palavra.substr(j, i - j))) {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
    }

    return dp[tamanho];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int D;
    while (cin >> D) {
        unordered_set<string> dicionario;
        
        for (int i = 0; i < D; ++i) {
            string palavra;
            cin >> palavra;
            dicionario.insert(palavra);
        }

        int U;
        cin >> U;
        vector<string> palavrasAlvo(U);

        for (int i = 0; i < U; ++i) {
            cin >> palavrasAlvo[i];
        }

        for (const string& palavra : palavrasAlvo) {
            cout << contarFormas(palavra, dicionario) << '\n';
        }
    }

}
