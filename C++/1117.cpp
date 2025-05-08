#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int valida = 0;
    double n, soma =0;
    while(valida != 2){
        cin >> n;
        if(n < 0 || n > 10){
            cout << "nota invalida" << endl;
        } else {
            soma += n;
            valida++;
        }
    }
    cout << fixed << setprecision(2);
    cout << "media = " << soma/2 << endl;

}
