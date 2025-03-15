#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

long int HexParaInt(const char *);
long int StrParaInt(const char *);

int main() {
    char numero[12];
    while (cin >> numero && numero[0] != '-') {
        if (numero[0] == '0' && numero[1] == 'x')
            cout << HexParaInt(numero) << endl;
        else
            cout << "0x" << uppercase << hex << StrParaInt(numero) << endl;
    }

    return 0;
}

long int StrParaInt(const char *str) {
    long int tamanho, resultado, multiplicador;

    for (tamanho = strlen(str) - 1, multiplicador = 1, resultado = 0; tamanho >= 0; tamanho--, multiplicador *= 10) {
        resultado += (str[tamanho] - 48) * multiplicador;
    }

    return resultado;
}

long int HexParaInt(const char *str) {
    long int resultado = 0;
    int i = 0;
    size_t tamanho = strlen(str) - 1;

    for (; str[tamanho] != 'x'; i++, tamanho--) {
        if (str[tamanho] >= 'A' && str[tamanho] <= 'F')
            resultado += (str[tamanho] - 'A' + 10) * pow(16, i);
        else if (str[tamanho] >= 'a' && str[tamanho] <= 'f')
            resultado += (str[tamanho] - 'a' + 10) * pow(16, i);
        else
            resultado += (str[tamanho] - '0') * pow(16, i);
    }

    return resultado;
}