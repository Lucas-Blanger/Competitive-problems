#include <iostream>
#include <cmath>
using namespace std;

bool somaDosQuadrados(int n) {
    if (n < 0) 
        return false;

    for (int a = 0; a * a <= n; ++a) {
        int bQuadrado = n - a * a;
        int b = static_cast<int>(sqrt(bQuadrado));
        if (b * b == bQuadrado) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    while (cin >> n) {
        if (somaDosQuadrados(n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
