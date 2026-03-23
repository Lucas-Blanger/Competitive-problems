#include <bits/stdc++.h>

using namespace std;

int contarCaminhos(vector<string>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    const int MOD = 1e9+7;
    
    vector<vector<int>> dp(n, vector<int>(m, 0));
    

    if (grid[0][0] == '*') return 0;
    
    dp[0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            if (grid[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }
            
            if (i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }
    }
    
    return dp[n-1][m-1];
}

int main(){
    int n;
    cin >> n;
    vector<string> grid(n);

    for(int i = 0; i < n; i++){
        cin >> grid[i];
 
    }

    cout << contarCaminhos(grid) << endl;


}