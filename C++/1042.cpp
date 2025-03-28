#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int a, b, c, menor, meio, maior;
    cin >> a >> b >> c;

    if(a < b && a < c){
        menor = a;
    } else if(b < a && b < c){
        menor = b;
    } else {
        menor = c;
    }  
    if((a > b && a < c) || (a < b && a > c)){
        meio = a;
    } else if((b > a && b < c) || (b < a && b > c)){
        meio = b;
    } else {
        meio = c;
    }

    if(a > b && a > c){
        maior = a;
    } else if(b > a && b > c){
        maior = b;
    } else {
        maior = c;
    }

    cout << menor << endl;
    cout << meio << endl;
    cout << maior << endl;

    cout << "" << endl;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

}



