#include <bits/stdc++.h>



using namespace std;

int dp[51][51][51];


int main() {
    int n, k;
    cin >> n >> k;


    vector<int> itens(n);

    for (int i = 0; i < n; i++)
        cin >> itens[i];


    vector<int> capacidade(k);
    for (int i = 0; i < k; i++)
        cin >> capacidade[i];


    while ((int)capacidade.size() < 3)
        capacidade.push_back(0);

    int C1 = capacidade[0], C2 = capacidade[1], C3 = capacidade[2];

    for (int i = 0; i <= 50; i++)
        for (int j = 0; j <= 50; j++)
            for (int l = 0; l <= 50; l++)
                dp[i][j][l] = 0;

    for (int s = 0; s < n; s++) {
        int song = itens[s];
        for (int c1 = C1; c1 >= 0; c1--) {
            for (int c2 = C2; c2 >= 0; c2--) {
                for (int c3 = C3; c3 >= 0; c3--) {
                    int val = dp[c1][c2][c3];
                    if (c1 >= song) val = max(val, dp[c1 - song][c2][c3] + song);
                    if (c2 >= song) val = max(val, dp[c1][c2 - song][c3] + song);
                    if (c3 >= song) val = max(val, dp[c1][c2][c3 - song] + song);
                    dp[c1][c2][c3] = val;
                }
            }
        }
    }

    cout << dp[C1][C2][C3] << endl;

}