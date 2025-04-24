#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int pos = 0;
    double x, soma=0, media;
    for(int i = 0; i <= 5; i++){
        cin >> x;
        if(x >= 0){
            pos++;
            soma += x;
        }
    }
    media = soma / pos;

    cout << pos << " valores positivos" << endl;
    cout << fixed << setprecision(1);
    cout << media << endl;
}