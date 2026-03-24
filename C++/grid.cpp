#include <bits/stdc++.h>
using namespace std;

int contarCaminhos(int m, int n, int K) {

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    dp[0][0] = 1;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {

            if (i > 0)
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % K;

            if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % K;
        }
    }

    return dp[m][n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int m, n, K;
        cin >> m >> n >> K;

        cout << contarCaminhos(m, n, K) << "\n";
    }
}