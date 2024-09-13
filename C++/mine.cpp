#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> baralhos(N);

    for (int i = 0; i < N; ++i) {
        int Mi;
        cin >> Mi;
        baralhos[i].resize(Mi);
        for (int j = 0; j < Mi; ++j) {
            cin >> baralhos[i][j];
        }
    }

    vector<int> mao;
    string senha;

    for (int i = 0; i < N; ++i) {
        unordered_map<int, int> contador;

        for (int carta : baralhos[i]) {
            mao.push_back(carta);
        }

        for (int carta : mao) {
            contador[carta]++;
        }

        vector<int> nova_mao;
        for (int carta : mao) {
            if (contador[carta] % 2 == 1) {
                nova_mao.push_back(carta);
            }
            contador[carta] = 0; 
        }
        mao = nova_mao;

        long long soma = 0;
        for (int carta : mao) {
            soma += (1LL << carta); 
        }


        senha += to_string(mao.size());
    }

    cout << senha << endl;

    return 0;
}
