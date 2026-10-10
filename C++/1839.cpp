
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

long long fat[2505], invFat[2505];

long long modPow(long long a, long long b) {
    long long r = 1;

    while (b > 0) {
        if (b & 1)
            r = r * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return r;
}

long long comb(int n, int k) {
    if (k < 0 || k > n)
        return 0;

    return fat[n] * invFat[k] % MOD
           * invFat[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<string> grid(N);

    for (int i = 0; i < N; i++)
        cin >> grid[i];

    int maxArea = N * M;

    fat[0] = 1;
    for (int i = 1; i <= maxArea; i++)
        fat[i] = fat[i - 1] * i % MOD;

    invFat[maxArea] = modPow(fat[maxArea], MOD - 2);

    for (int i = maxArea; i >= 1; i--)
        invFat[i - 1] = invFat[i] * i % MOD;

    int xA, yA, xB, yB;

    while (cin >> xA >> yA >> xB >> yB) {
        int area = (xB - xA + 1) * (yB - yA + 1);
        int paredes = 0;

        for (int i = xA - 1; i < xB; i++) {
            for (int j = yA - 1; j < yB; j++) {
                if (grid[i][j] == '#')
                    paredes++;
            }
        }

        long long r = (comb(area, paredes) - 1 + MOD) % MOD;

        cout << r << '\n';
    }

}
