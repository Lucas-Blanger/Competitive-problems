#include <bits/stdc++.h>

using namespace std;

int trocoDP(int valor, vector<int>& moedas) {
    vector<int> dp(valor + 1, INT_MAX);
    dp[0] = 0;
    
    for (int v = 1; v <= valor; v++) {
        for (int moeda : moedas) {
            if (moeda <= v && dp[v - moeda] != INT_MAX) {
                dp[v] = min(dp[v], dp[v - moeda] + 1);
            }
        }
    }
    
    return (dp[valor] == INT_MAX) ? -1 : dp[valor];
}



int main() {
    int inst;
    cin >> inst;
    while(inst--){
        int n,m;
        cin >> n >> m;

        vector<int> blocos(n);

        for(int i = 0; i < n; i++){
            cin >> blocos[i];
        }

        int r = trocoDP(m, blocos);

        cout << r << endl;


    }

}