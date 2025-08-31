#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<char, char>> troca(n);
    for (int i = 0; i < n; i++) {
        char a, b;
        cin >> a >> b;
        troca[i] = {a, b};
    }

    cin.ignore(); 

    for (int i = 0; i < m; i++) {
        string frase;
        getline(cin, frase);

        for (size_t j = 0; j < frase.size(); j++) {
            for (int k = 0; k < n; k++) {
                if (frase[j] == troca[k].first) {
                    frase[j] = troca[k].second;
                    break;
                }
                if (frase[j] == troca[k].second) {
                    frase[j] = troca[k].first;
                    break;
                }
            }
        }

        cout << frase << "\n";
    }

}
