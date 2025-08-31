#include <bits/stdc++.h>
using namespace std;

int pow2mod10(long long k) {
    if (k == 0) return 1;
    int a[4] = {6, 2, 4, 8};
    return a[k % 4];
}

int lastNonZero(long long n) {
    static int t[5] = {1, 1, 2, 6, 4};
    if (n < 5) return t[n];
    return (int)( (long long)lastNonZero(n / 5) * lastNonZero(n % 5) * pow2mod10(n / 5) % 10 );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    int inst = 1;
    while (cin >> n) {
        cout << "Instancia " << inst++ << "\n";
        cout << lastNonZero(n) << "\n\n";
    }

}
