
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    vector<pair<long long, long long>> aux(n);

    for (long long i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        aux[i] = {a, b};
    }

    long long l = 1, r = 2e18;

    while (l < r) {
        long long mid = l + (r - l) / 2;
        long long cont = 0;

        for (long long i = 0; i < n; i++) {
            long long a = aux[i].first;
            long long b = aux[i].second;

            if (mid >= a) {
                cont += 1 + (mid - a) / b;
            }

            if (cont >= k)
                break;
        }

        if (cont >= k)
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << '\n';

}
