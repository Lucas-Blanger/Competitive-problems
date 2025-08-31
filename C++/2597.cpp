#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;
    cin >> C;
    while (C--) {
        long long N;
        cin >> N;
        long long r = sqrt(N);
        cout << (N - r) << "\n";
    }
    return 0;
}
