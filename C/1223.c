#include <stdio.h>
#include <math.h>
#include <float.h>

#define EPS 1e-10
#define MAX 1000

typedef struct {
    double x, y;
} Ponto;

int cmp(double x, double y, double tol) {
    if (x < y - tol) return -1; 
    if (x > y + tol) return 1;   
    return 0;  
}

Ponto soma(Ponto a, Ponto b) {
    Ponto resultado = {a.x + b.x, a.y + b.y};
    return resultado;
}

Ponto sub(Ponto a, Ponto b) {
    Ponto resultado = {a.x - b.x, a.y - b.y};
    return resultado;
}

Ponto mul(Ponto a, double t) {
    Ponto resultado = {a.x * t, a.y * t};
    return resultado;
}

Ponto divPonto(Ponto a, double t) {
    Ponto resultado = {a.x / t, a.y / t};
    return resultado;
}

double produtoEscalar(Ponto a, Ponto b) {
    return a.x * b.x + a.y * b.y;
}

double produtoVetorial(Ponto a, Ponto b) {
    return a.x * b.y - a.y * b.x;
}

double segDistancia(Ponto p, Ponto q, Ponto r) {
    Ponto A = sub(r, q);
    Ponto B = sub(r, p);
    Ponto C = sub(q, p);
    double a = produtoEscalar(A, A);
    double b = produtoEscalar(B, B);
    double c = produtoEscalar(C, C);
    if (cmp(b, a + c, EPS) >= 0) return sqrt(a);
    else if (cmp(a, b + c, EPS) >= 0) return sqrt(b);
    else return fabs(produtoVetorial(A, B)) / sqrt(c);
}

double segs_distance(Ponto p, Ponto q, Ponto r, Ponto s) {
    double d1 = segDistancia(p, q, r);
    double d2 = segDistancia(p, q, s);
    double d3 = segDistancia(r, s, p);
    double d4 = segDistancia(r, s, q);
    return fmin(fmin(d1, d2), fmin(d3, d4));
}

int main() {
    int N, k;
    double L, H, r;
    Ponto Pi[MAX], Pf[MAX];

    while (scanf("%d", &N) != EOF) {
        r = DBL_MAX;
        scanf("%lf %lf", &L, &H);
        
        for (k = 0; k < N; k++) {
            if (k % 2 == 0)
                Pi[k].x = 0.0;
            else
                Pi[k].x = L;

            scanf("%lf %lf %lf", &Pi[k].y, &Pf[k].x, &Pf[k].y);
        }

        for (k = 0; k < N; k++) {
            if (k % 2 == 0) {
                r = fmin(r, segs_distance((Ponto){L, 0}, (Ponto){L, H}, Pi[k], Pf[k]));
            } else {
                r = fmin(r, segs_distance((Ponto){0, 0}, (Ponto){0, H}, Pi[k], Pf[k]));
            }
            if (k > 0) {
                r = fmin(r, segs_distance(Pi[k], Pf[k], Pi[k - 1], Pf[k - 1]));
            }
        }

        printf("%.2f\n", r);
    }

}
