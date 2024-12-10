#include <iostream>
#include <cstdio>

#define MAXN 10000

using namespace std;

typedef long long int64;

struct Matriz {
    int64 mat[2][2];
};

Matriz multiplicaMatriz(Matriz a, Matriz b, int64 m) {

    Matriz resultado;

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j) {

            resultado.mat[i][j] = 0;
            for (int k = 0; k < 2; ++k)
                resultado.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % m;
        }
    return resultado;
}

int64 potenciaMatriz(Matriz base, int64 expoente, int64 m) {
    Matriz resultado;

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            resultado.mat[i][j] = (i == j);

    while (expoente) {
        
        if (expoente & 1)
            resultado = multiplicaMatriz(resultado, base, m);
        base = multiplicaMatriz(base, base, m);
        expoente >>= 1;
    }
    return resultado.mat[0][0];
}

int main() {
    int caso = 1;
    int64 a, b;
    while (scanf("%lld %lld", &a, &b) && a + b) {
        Matriz base;
        base.mat[0][0] = base.mat[0][1] = base.mat[1][0] = 1;
        base.mat[1][1] = 0;
        if (a <= 1)
            printf("Case %d: %lld %lld 1\n", caso++, a, b);
        else
            printf("Case %d: %lld %lld %lld\n", caso++, a, b, (2 * potenciaMatriz(base, a, b) - 1) % b);
    }
    return 0;
}
