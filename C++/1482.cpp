#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int LIMITE = 420;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0) {
        vector<int> t(n);
        for (int i = 0; i < n; i++) cin >> t[i];

        vector<vector<int>> dist(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> dist[i][j];

        vector<vector<int>> dp(1<<n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            dp[1<<i][i] = t[i];
        }

        for (int mask = 0; mask < (1<<n); mask++) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1<<i))) continue;
                if (dp[mask][i] > LIMITE) continue;

                for (int j = 0; j < n; j++) {
                    if (mask & (1<<j)) continue;

                    int newMask = mask | (1<<j);
                    int newCost = dp[mask][i] + dist[i][j] + t[j];

                    dp[newMask][j] = min(dp[newMask][j], newCost);
                }
            }
        }

        int r = 0;

        for (int mask = 0; mask < (1<<n); mask++) {
            for (int i = 0; i < n; i++) {
                if (dp[mask][i] <= LIMITE) {
                    r = max(r, __builtin_popcount(mask));
                }
            }
        }

        cout << r << "\n";
    }
}