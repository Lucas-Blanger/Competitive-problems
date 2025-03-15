#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <cmath>

using namespace std;

int main(){
    double r, resposta;
    double pi = 3.14159;
    cin >> r;
    resposta = (4.0 / 3.0) * pi * pow(r, 3.0);
    cout << fixed << setprecision(3);

    cout << "VOLUME = " << resposta << endl;
    
}
