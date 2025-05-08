#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int valida = 0,novo =1,p;
    double n, soma =0;
    while(novo != 2){
        while(valida != 2){
            cin >> n;
            if(n < 0 || n > 10){
                cout << "nota invalida" << endl;
            } else {
                soma += n;
                valida++;
                p = 1;
            }
        }
        cout << fixed << setprecision(2);
        if(p == 1){
            cout << "media = " << soma/2 << endl;
            p = 0;
            soma = 0;
        }
        cout << "novo calculo (1-sim 2-nao)" << endl;
        cin >> novo;
        if(novo == 1){
            valida = 0;
        }
    }
}
