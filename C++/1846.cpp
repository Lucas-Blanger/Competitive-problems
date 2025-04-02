#include <iostream>
#include <string>
using namespace std;

struct String {
    string numeros;
};

String unidade[10] = {"zero", "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"};
String especial[10] = {"dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
String dezena[9] = {"vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa", "cem"};
String centena[9] = {"cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};

int main() {
    int n;
    bool flag;

    while (cin >> n) {
        flag = false;
        if (n == 0) {
            cout << "zero" << endl;
        } else {
            if (n >= 10000) flag = true;
            if (n >= 100000) {
                if (n <= 100999)
                    cout << "cem", n -= 100000;
                else
                    cout << centena[n / 100000 - 1].numeros;
                n %= 100000;
                if (n == 0) {
                    cout << " mil" << endl;
                    continue;
                } else if (n < 1000)
                    if (n % 100 && n > 100)
                        cout << " mil ";
                    else
                        cout << " mil e ";
                else
                    cout << " e ";
            }
            if (n >= 20000) {
                cout << dezena[n / 10000 - 2].numeros;
                n %= 10000;
                if (n == 0) {
                    cout << " mil" << endl;
                    continue;
                } else if (n < 1000)
                    if (n % 100 && n > 100)
                        cout << " mil ";
                    else
                        cout << " mil e ";
                else
                    cout << " e ";
            }
            if (n >= 10000) {
                cout << especial[(n / 1000) % 10].numeros;
                n %= 1000;
                if (n == 0) {
                    cout << " mil" << endl;
                    continue;
                } else if (n < 1000 && n)
                    if (n % 100 && n > 100)
                        cout << " mil ";
                    else
                        cout << " mil e ";
                else
                    cout << " e ";
            }
            if (n >= 1000) {
                if (n >= 2000 || flag)
                    cout << unidade[n / 1000].numeros << " ";
                if (n % 1000 == 0)
                    cout << "mil";
                n %= 1000;
                if (n == 0) {
                    cout << endl;
                    continue;
                } else if (n < 100 || (n < 1000 && n % 100 == 0))
                    cout << "mil e ";
                else
                    cout << "mil ";
            }
            if (n >= 100) {
                if (n == 100)
                    cout << "cem";
                else
                    cout << centena[n / 100 - 1].numeros;
                n %= 100;
                if (n == 0) {
                    cout << endl;
                    continue;
                } else
                    cout << " e ";
            }
            if (n >= 20) {
                cout << dezena[n / 10 - 2].numeros;
                n %= 10;
                if (n == 0) {
                    cout << endl;
                    continue;
                } else
                    cout << " e ";
            }
            if (n >= 10)
                cout << especial[n % 10].numeros, n = 0;
            if (n < 10 && n)
                cout << unidade[n].numeros;
            cout << endl;
        }
    }
}