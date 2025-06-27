#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;


int main () {
    int n;
    cin >> n;

    int x[n], menor = 3000000, pos = 0;

    for(int i = 0; i < n; i++){
        cin >> x[i];
        if(x[i] < menor){
            menor = x[i];
            pos = i;
        }
    }

    cout << "Menor valor: " << menor << endl;
    cout << "Posicao: " << pos << endl;

}
    




