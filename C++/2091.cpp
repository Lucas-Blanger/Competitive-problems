#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        if (n == 0) break;

        unordered_map<long long, int> v;
        for (int i = 0; i < n; ++i) {
            long long a;
            cin >> a;
            v[a]++;
        }

        for (auto p : v) {
            if (p.second % 2 != 0) {
                cout << p.first << '\n';
                break;
            }
        }
    }


}
