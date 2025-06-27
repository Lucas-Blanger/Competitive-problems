#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;


int main () {
    double n[100];
    double valor;

    cin >> valor;
    n[0] = valor;
    cout << fixed << setprecision(4);

    for(int i = 1; i < 100; i++){
        n[i] = n[i-1] / 2.0;
    }
    for(int i = 0; i < 100; i++){
       cout << "N[" << i << "] = " << n[i] << endl;
    }



}
    





