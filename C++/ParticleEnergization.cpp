#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long y, k;
    cin >> y >> k;

    vector<long long> fat;
    long long n = 2;

    while (y >= n * n) {
        while (y % n == 0) {
            fat.push_back(n);
            y /= n;
        }
        n++;
    }
    if (y != 1) fat.push_back(y);

    long long ans = 1;
    long long g = 1;

    for (long long f : fat) {
        long long app = min(f - 1, k);
        ans += g * app;
        g *= f;
        k -= app;
    }

    ans += k * g;
    cout << ans << endl;

}
