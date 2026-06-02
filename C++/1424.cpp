#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;

    while (cin >> n >> m) {
        unordered_map<int, vector<int>> pos;

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            pos[x].push_back(i);
        }

        while (m--) {
            int k, v;
            cin >> k >> v;

            if (pos[v].size() < k)
                cout << 0 << '\n';
            else
                cout << pos[v][k - 1] << '\n';
        }
    }

}