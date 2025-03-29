#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double salario, salario2, total;

    cin >> salario;
    cout << fixed << setprecision(2);

    if(salario <= 2000){
        cout << "Isento" << endl;
    }else{
        if(salario > 4500.0) {
            salario2 = salario - 4500.00;
            salario = salario - salario2;
            total = total + salario2 * 0.28;
        } 
        if(salario >= 3000.01 && salario <= 4500.00){
            salario2 = salario - 3000.00;
            salario = salario - salario2;
            total = total + salario2 * 0.18;
        }
        if(salario >= 2000.01 && salario <= 3000.00){
            salario2 = salario - 2000.00;
            salario = salario - salario2;
            total = total + salario2 * 0.08;
        }
        cout << "R$ " << total << endl;
}
}


    


