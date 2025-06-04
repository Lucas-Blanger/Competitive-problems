#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool p(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return false;
    return true;
}

int main() {
    int m;
    while (cin >> m) {
        vector<int> v(m);
        for (int i = 0; i < m; i++) cin >> v[i];
        int n;
        cin >> n;
        int s = 0;
        for (int i = m - 1; i >= 0; i -= n)
            s += v[i];
        if (p(s)) cout << "You’re a coastal aircraft, Robbie, a large silver aircraft.\n";
        else cout << "Bad boy! I’ll hit you.\n";
    }

}
