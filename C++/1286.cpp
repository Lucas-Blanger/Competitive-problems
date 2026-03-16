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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        int p;
        cin >> p;

        vector<int> peso(n), valor(n);
        for (int i = 0; i < n; i++)
            cin >> valor[i] >> peso[i];


        cout << knapsack(n, p, peso, valor) << " min." << endl;




    }

    
}