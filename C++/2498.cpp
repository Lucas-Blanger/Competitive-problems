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
    int n,c;
    int casos = 0;
    while(true){
        cin >> n >> c;
        if(n == 0 && c == 0) break;
        casos++;
        vector<int> peso(n), valor(n);

        for(int i = 0; i < n; i++){
            cin >> peso[i] >> valor[i];
        }

        int r = knapsack(n, c, peso, valor);

        cout << "Caso " << casos << ": " << r << endl;
    }
   

}
