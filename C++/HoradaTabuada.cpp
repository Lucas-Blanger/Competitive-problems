#include <iostream>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    int cont = 0;
    for (int i = 1; i <= n; i++) {
        if (x % i == 0) {
            int j = x / i;
            if (j <= n) {
                cont++;
            }
        }
    }

    cout << cont << endl;
}
