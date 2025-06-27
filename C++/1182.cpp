#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    int valor, cont = 0;
    char op;

    double mat[12][12], soma = 0.0;

    cin >> valor;
    cin >> op;

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < 12; i++){
        soma += mat[i][valor];
        cont++;
    }

    cout << fixed << setprecision(1);
    if(op == 'S'){
        cout << soma << endl;
    } else{
        cout << soma / cont << endl;
    }

}
