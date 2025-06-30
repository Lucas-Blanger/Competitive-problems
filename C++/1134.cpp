#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int n, alco = 0, gasolina = 0, diesel = 0;
    while (true){
        cin >> n;
        if(n == 4){
            break;
        }

        if(n > 4 || n < 1){
            continue;
        }


        if(n == 1){
            alco++;
        }
        if(n == 2){
            gasolina++;
        }
        if(n == 3){
            diesel++;
        }
        
    }

    cout << "MUITO OBRIGADO" << endl;
    cout << "Alcool: " << alco << endl;
    cout << "Gasolina: " << gasolina << endl;
    cout << "Diesel: " << diesel << endl;


}
