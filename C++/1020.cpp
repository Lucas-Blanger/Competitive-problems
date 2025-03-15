#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <cmath>

using namespace std;

int main(){
    int idade, ano, mes, dia, resto;
    cin >> idade;
    ano = (idade / 365) ;
    resto = idade % 365;
    mes = resto / 30;
    resto = resto % 30;
    dia = resto;

    cout << ano << " ano(s)" << endl;
    cout << mes << " mes(es)" << endl;
    cout << dia << " dia(s)" << endl;
    
}