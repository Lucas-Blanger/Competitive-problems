#include <iostream>
using namespace std;

long long calcularPisano(long long m) {
    long long anterior = 0, atual = 1, prox;
    for (long long i = 0; i < m * m; i++) {
        prox = (anterior + atual) % m;
        anterior = atual;
        atual = prox;
        if (anterior == 0 && atual == 1) {
            return i + 1; 
        }
    }
    return -1; 
}

long long fibonacciMod(long long n, long long m) {
    n = n % calcularPisano(m);
    if (n <= 1)
        return n;

    long long anterior = 0, atual = 1;
    for (long long i = 0; i < n - 1; i++) {
        long long temp = atual;
        atual = (anterior + atual) % m;
        anterior = temp;
    }
    return atual % m;
}

int main() {
    long long n, m;
    while (cin >> n >> m) {
        cout << fibonacciMod(fibonacciMod(n, calcularPisano(m)), m) << endl;
    }
    return 0;
}
