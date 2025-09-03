#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p;
    cin >> p;
    int n = p / 2;

    vector<int> vis(p, 0);

    auto f = [&](int i) {
        if (i < n) return 2 * i + 1;
        return 2 * (i - n);
    };

    ll ans = 1;
    for (int i = 0; i < p; i++) {
        if (!vis[i]) {
            int cur = i, len = 0;
            while (!vis[cur]) {
                vis[cur] = 1;
                cur = f(cur);
                len++;
            }
            ans = lcm(ans, (ll)len); 
        }
    }

    cout << ans << "\n";
}
