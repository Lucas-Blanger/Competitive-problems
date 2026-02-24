#include <bits/stdc++.h>


using namespace std;

int trocoDP(int valor, vector<int>& moedas) {
    vector<int> dp(valor + 1, -1);
    dp[0] = 0;

    for (int moeda : moedas) {
        for (int v = valor; v >= moeda; v--) {
            if (dp[v - moeda] != -1)
                dp[v] = 1;
        }
    }

    return dp[valor] != -1;
}

int main() {


    int v,m;
    cin >> v >> m;

    vector<int> moedas(m);
    for(int i = 0; i < m; i++){
        cin >> moedas[i];
    }

    int r = trocoDP(v, moedas);
    if(r == 0) cout << "N\n";
    else cout << "S\n";

   

}


