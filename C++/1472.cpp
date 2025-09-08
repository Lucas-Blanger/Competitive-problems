#include <bits/stdc++.h>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while (cin >> N) {
        vector<long long> X(N);
        long long P = 0;
        for (int i = 0; i < N; i++) {
            cin >> X[i];
            P += X[i];
        }

        if (P % 3 != 0) {
            cout << 0 << "\n";
            continue;
        }
        long long step = P / 3;

        vector<long long> pos(N);
        pos[0] = 0;
        for (int i = 1; i < N; i++) {
            pos[i] = pos[i-1] + X[i-1];
        }

        unordered_set<long long> pontos(pos.begin(), pos.end());

        long long count = 0;
        for (int i = 0; i < N; i++) {
            long long p1 = (pos[i] + step) % P;
            long long p2 = (pos[i] + 2*step) % P;
            if (pontos.count(p1) && pontos.count(p2)) {
                count++;
            }
        }

        cout << count / 3 << "\n";
    }

}