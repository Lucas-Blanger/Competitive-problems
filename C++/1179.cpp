#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;


int main () {
    int par[5], impar[5], valor, contPar = 0, contImpar = 0;

    for(int i = 0; i < 15; i++){
        cin >> valor;
        if(valor % 2 == 0){
            if(contPar < 5){
                par[contPar] = valor;
                contPar++;
            } else {
                contPar = 0;
                for(int i = 0; i < 5; i++){
                    cout << "par[" << i << "] = " << par[i] << endl;
                }
                par[contPar] = valor;
                contPar++;
            }
        } else {
             if(contImpar < 5){
                impar[contImpar] = valor;
                contImpar++;
            } else {
                contImpar = 0;
                for(int i = 0; i < 5; i++){
                    cout << "impar[" << i << "] = " << impar[i] << endl;
                }
                impar[contImpar] = valor;
                contImpar++;
            }

        }

    }

    
    for(int i = 0; i < contImpar; i++){
        cout << "impar[" << i << "] = " << impar[i] << endl;
    }
    for(int i = 0; i < contPar; i++){
        cout << "par[" << i << "] = " << par[i] << endl;
    }



}
    





