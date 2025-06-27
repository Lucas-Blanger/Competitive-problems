#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;


int main () {
    int t, cont;
    int N[1000];

    cin >> t;
    
    cont = 0;

    while (cont < 1000) {
        for (int j = 0; j < t && cont < 1000; j++) {
            N[cont] = j;
            cout << "N[" << cont << "] = " << N[cont] << endl;
            cont++;
        }
    }

}
    





