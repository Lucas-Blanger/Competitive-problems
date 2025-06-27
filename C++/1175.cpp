#include <iostream>
#include <cstdio>

using namespace std;


int main () {
    int N[20];
    int aux;

    for(int i = 0; i < 20; i++){
        cin >> N[i];
    }

    for(int i = 0; i < 10; i++){
        aux = N[i];
        N[i] = N[19 - i];
        N[19 - i] = aux;
    }

    for(int i = 0; i < 20; i++){
        cout << "N[" << i << "] = " << N[i] << endl;
    }
  

}
    





