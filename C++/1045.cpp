#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, maior, meio, menor;
    cin >> a >> b >> c;

    if (a >= b && a >= c) {
        maior = a;
        if (b >= c) {
            meio = b;
            menor = c;
        } else {
            meio = c;
            menor = b;
        }
    } else if (b >= a && b >= c) {
        maior = b;
        if (a >= c) {
            meio = a;
            menor = c;
        } else {
            meio = c;
            menor = a;
        }
    } else {
        maior = c;
        if (a >= b) {
            meio = a;
            menor = b;
        } else {
            meio = b;
            menor = a;
        }
    }


    if (maior >= (meio + menor)) {
        cout << "NAO FORMA TRIANGULO" << endl;
    } else {
        if (pow(maior, 2) == (pow(meio, 2) + pow(menor, 2))) {
            cout << "TRIANGULO RETANGULO" << endl;
        }
        if (pow(maior, 2) > (pow(meio, 2) + pow(menor, 2))) {
            cout << "TRIANGULO OBTUSANGULO" << endl;
        }
        if (pow(maior, 2) < (pow(meio, 2) + pow(menor, 2))) {
            cout << "TRIANGULO ACUTANGULO" << endl;
        }
        if (maior == meio && meio == menor) {
            cout << "TRIANGULO EQUILATERO" << endl;
        }
        if ((maior == meio && meio != menor) || (meio == menor && menor != maior)) {
            cout << "TRIANGULO ISOSCELES" << endl;
        }
    }

}
