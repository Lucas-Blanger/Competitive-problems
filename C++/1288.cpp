#include <bits/stdc++.h>

using namespace std;

int knapsack(int n, int W, vector<int>& peso, vector<int>& valor) {
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= peso[i]; w--) {
            dp[w] = max(dp[w], valor[i] + dp[w - peso[i]]);
        }
    }

    return dp[W];
}



int main() {
    int c;
    cin >> c;

    while(c--){
        int n;
        cin >> n;
        vector<int> peso(n), valor(n);
        for (int i = 0; i < n; i++)
            cin >> valor[i] >> peso[i];

        int w,r;
        cin >> w >> r;

        int resposta = knapsack(n, w, peso, valor);;

        if (resposta >= r) cout << "Missao completada com sucesso" << endl;
        else cout << "Falha na missao" << endl;




    }
   

}
