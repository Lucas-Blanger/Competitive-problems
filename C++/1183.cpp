#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char operacao;
    cin >> operacao;

    double matriz[12][12];
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> matriz[i][j];
        }
    }

    double soma = 0.0;
    int contador = 0;

    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            soma += matriz[i][j];
            contador++;
        }
    }

    if (operacao == 'S') {
        cout << fixed << setprecision(1) << soma << endl;
    } else if (operacao == 'M') {
        cout << fixed << setprecision(1) << soma / contador << endl;
    }

}
