#include <bits/stdc++.h>

using namespace std;

int main(){
    double salario;
    cin >> salario;
    double novoS, reajuste;
    int percentual;

    if(salario <= 400.00){
        percentual = 15;
        novoS = (salario * 115) / 100;
        reajuste = novoS - salario;
    } else if(salario <= 800.00 && salario > 400.00){
        percentual = 12;
        novoS = (salario * 112) / 100;
        reajuste = novoS - salario;
    } else if(salario <= 1200.00 && salario > 800.00){
        percentual = 10;
        novoS = (salario * 110) / 100;
        reajuste = novoS - salario;
    } else if(salario <= 2000.00 && salario > 1200.00){
        percentual = 7;
        novoS = (salario * 107) / 100;
        reajuste = novoS - salario;
    } else if(salario > 2000.00){
        percentual = 4;
        novoS = (salario * 104) / 100;
        reajuste = novoS - salario;
    }
    cout << fixed << setprecision(2);
    cout << "Novo salario: " << novoS << endl;
    cout << "Reajuste ganho: " << reajuste << endl;
    cout << "Em percentual: " << percentual << " %" << endl;
}