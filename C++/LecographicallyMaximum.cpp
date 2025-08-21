#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> cnt(32, 0);
    for (int x : a) {
        for (int b = 0; b < 32; b++) {
            if (x & (1 << b)) cnt[b]++;
        }
    }

    vector<int> res(n, 0);

    for (int b = 31; b >= 0; b--) {
        for (int i = 0; i < n && cnt[b] > 0; i++, cnt[b]--) {
            res[i] |= (1 << b);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << (i + 1 == n ? '\n' : ' ');
    }
}