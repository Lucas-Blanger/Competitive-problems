#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

long long coinChangeWays(vector<int>& coins, int x) {
    
    vector<long long> dp(x + 1, 0);

    dp[0] = 1;

    for (int coin : coins) {
        for (int i = coin; i <= x; i++) {
            dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }

    return dp[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin >> n >> x;

    vector<int> coins(n);

    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    cout << coinChangeWays(coins, x) << endl;
}