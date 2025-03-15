#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){
    double valor;
    cin >> valor;

    int n = int(valor);  
    int centavos = round((valor - n) * 100);  

    int n100 = n / 100;
    n = n % 100;
    int n50 = n / 50;
    n = n % 50;
    int n20 = n / 20;
    n = n % 20;
    int n10 = n / 10;
    n = n % 10;
    int n5 = n / 5;
    n = n % 5;
    int n2 = n / 2;
    n = n % 2;
    int n1 = n / 1;

    int ns50 = centavos / 50;
    centavos = centavos % 50;
    int ns25 = centavos / 25;
    centavos = centavos % 25;
    int ns10 = centavos / 10;
    centavos = centavos % 10;
    int ns05 = centavos / 5;
    centavos = centavos % 5;
    int ns01 = centavos;

    cout << "NOTAS:" << endl;
    cout << n100 << " nota(s) de R$ 100.00" << endl;
    cout << n50 << " nota(s) de R$ 50.00" << endl;
    cout << n20 << " nota(s) de R$ 20.00" << endl;
    cout << n10 << " nota(s) de R$ 10.00" << endl;
    cout << n5 << " nota(s) de R$ 5.00" << endl;
    cout << n2 << " nota(s) de R$ 2.00" << endl;

    cout << "MOEDAS:" << endl;
    cout << n1 << " moeda(s) de R$ 1.00" << endl;
    cout << ns50 << " moeda(s) de R$ 0.50" << endl;
    cout << ns25 << " moeda(s) de R$ 0.25" << endl;
    cout << ns10 << " moeda(s) de R$ 0.10" << endl;
    cout << ns05 << " moeda(s) de R$ 0.05" << endl;
    cout << ns01 << " moeda(s) de R$ 0.01" << endl;

}