#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<long long> notas(n);
        long long soma = 0;
        for (int i = 0; i < n; i++) {
            cin >> notas[i];
            soma += notas[i];
        }
        if (soma % n != 0) {
            cout << -1 << endl;
            continue;
        }
        long long x = soma / n;
        long long pos = 0;
        for (int i = 0; i < n; i++) {
            if (notas[i] > x) {
                pos += (notas[i] - x);
            }
        }
        cout << pos + 1 << endl; 
    }
}