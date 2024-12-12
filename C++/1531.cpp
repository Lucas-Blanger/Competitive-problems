#include <iostream>
#include <vector>
using namespace std;

int calcularPisano(int m) {
    vector<int> fibMod = {0, 1};
    for (int i = 2; i <= m * m; i++) {
        fibMod.push_back((fibMod[i - 1] + fibMod[i - 2]) % m);
        if (fibMod[i] == 1 && fibMod[i - 1] == 0) {
            return i - 1; 
        }
    }
    return -1; 
}

int fibonacciMod(long long n, int m) {
    if (n <= 1) return n;

    long long anterior = 0, atual = 1;
    for (long long i = 2; i <= n; i++) {
        long long temp = (anterior + atual) % m;
        anterior = atual;
        atual = temp;
    }
    return atual;
}

int main() {
    long long n;
    int m;

    while (cin >> n >> m) {
        int pisano = calcularPisano(m);

        int fibNmodPisano = fibonacciMod(n, pisano);

        int resultado = fibonacciMod(fibNmodPisano, m);

        cout << resultado << endl;
    }

    return 0;
}