
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> grau(N, 0);

        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;

            grau[a]++;
            grau[b]++;
        }

        bool r = (M > 0);

        for (int i = 0; i < N; i++) {
            if (grau[i] % 2 != 0) {
                r = false;
                break;
            }
        }

        cout << (r ? "Yes" : "No") << '\n';
    }

}
