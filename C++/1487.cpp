#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int W, vector<int>& peso, vector<int>& valor) {
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = peso[i]; w <= W; w++) {
            dp[w] = max(dp[w], valor[i] + dp[w - peso[i]]);
        }
    }

    return dp[W];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int instancia = 1;

    while(true){
        int n, t;
        cin >> n >> t;

        if(n == 0) break;

        vector<int> peso(n), valor(n);

        for(int i = 0; i < n; i++){
            cin >> peso[i] >> valor[i];
        }

        cout << "Instancia " << instancia++ << "\n";
        cout << knapsack(n, t, peso, valor) << "\n\n";
    }
}