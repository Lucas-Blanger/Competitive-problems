#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#define MAX 1000006
#define ull long long
using namespace std;


struct Valor {
    int x;
    ull v;


    inline bool operator <(const Valor& a) const {
        return this->x < a.x;
    }
};

Valor F[MAX];

int main() {
    int n, s, y;

    while(cin >> n >> s >> y) {

        for(int i = 0; i < s; i++) {
            cin >> F[i].x >> F[i].v;
        }


        sort(F, F + s);

        double minimo = 0, maximo = 0;


        for(int i = 0; i < s - 1; i++) {
            Valor a = F[i], b = F[i + 1];

            minimo += min(a.v, b.v) + (b.x - a.x - 1) * min(a.v, b.v) + abs(a.v - b.v) / 2.0;
            maximo += min(a.v, b.v) + (b.x - a.x - 1) * max(a.v, b.v) + abs(a.v - b.v) / 2.0;
        }


        if (y < minimo || y > maximo || ceil(minimo) != minimo) {
            cout << "N" << endl;
            continue;
        }

        cout << "S"; 

        ull atual = round(maximo); 


        for(int i = 0; i < s - 1; i++) {
            Valor a = F[i], b = F[i + 1];


            ull delta = (b.x - a.x - 1) * (max(a.v, b.v) - min(a.v, b.v));

            if (atual == y) {

                for(int x = a.x + 1; x < b.x; x++)
                    cout << " " << max(a.v, b.v);
            } else if (atual - delta > y) {

                atual -= delta;
                for(int x = a.x + 1; x < b.x; x++)
                    cout << " " << min(a.v, b.v);
            } else if (a.v < b.v) {

                for(int x = a.x + 1; x < b.x; x++) {
                    ull valor = max(a.v, b.v - (atual - y));
                    cout << " " << valor;
                    atual -= b.v - valor;
                }
            } else {
                ull adicionar = (atual - y) / (b.x - a.x - 1);
                ull resto = (atual - y) % (b.x - a.x - 1);
                for(int x = a.x + 1; x < b.x; x++) {
                    ull valor = a.v - adicionar - (b.x - x <= resto ? 1 : 0);
                    cout << " " << valor;
                    atual -= a.v - valor;
                }
            }
        }

        cout << endl;
    }
}
