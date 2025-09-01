#include <iostream>

using namespace std;

int main(){
    int x, y;
    cin >> x >> y;

    int cont = 0;
    int dif = 0;

    while(dif < y){
        dif+=y-x;
        cont++;
    }

    cout << cont << endl;
}