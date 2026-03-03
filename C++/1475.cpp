#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long c, t1, t2;

    while (cin >> n >> c >> t1 >> t2) {

        vector<long long> furos(n);
        for (int i = 0; i < n; i++)
            cin >> furos[i];

        sort(furos.begin(), furos.end());

        vector<long long> pontos(2 * n);
        for (int i = 0; i < n; i++) {
            pontos[i] = furos[i];
            pontos[i + n] = furos[i] + c;
        }

        long long r = LLONG_MAX;

        for (int start = 0; start < n; start++) {

            vector<long long> dp(n + 1, 0);

            for (int i = n - 1; i >= 0; i--) {

                int idx = start + i;

                long long limite1 = pontos[idx] + t1;
                int j1 = idx;

                while (j1 < start + n && pontos[j1] <= limite1)
                    j1++;

                long long custo1 = t1 + dp[j1 - start];

                long long limite2 = pontos[idx] + t2;
                int j2 = idx;

                while (j2 < start + n && pontos[j2] <= limite2)
                    j2++;

                long long custo2 = t2 + dp[j2 - start];

                dp[i] = min(custo1, custo2);
            }

            r = min(r, dp[0]);
        }

        cout << r << "\n";
    }

}