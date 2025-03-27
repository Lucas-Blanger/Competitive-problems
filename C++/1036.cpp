#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    double a, b, c, raiz, r1, r2;
    cin >> a >> b >> c;
    cout << fixed << setprecision(5);

    raiz = (pow(b, 2) - 4 * a * c);

    if(a == 0 || raiz < 0){
        cout << "Impossivel calcular" << endl;
    } else {
        r1 = (-b + sqrt(raiz)) / (2 * a);
        r2 = (-b - sqrt(raiz)) / (2 * a);

        cout << "R1 = " << r1 << endl;
        cout << "R2 = " << r2 << endl;
    }

    return 0;
}
