#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;


int main () {
    char o;
    double mat[12][12], soma = 0;
    int cont = 0;

    cin >> o;

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 1; i < 12; i++){
        for(int j = 12 - i; j < 12; j++){
            soma += mat[i][j];
            cont++;
        }
    }

    cout << fixed << setprecision(1);
    if(o == 'S'){
        cout << soma << endl;
    } else {
        cout << soma / cont << endl;
    }

}
    




