#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int Xf, Yf, Xi, Yi, Vi, R1, R2;

    while (cin >> Xf >> Yf >> Xi >> Yi >> Vi >> R1 >> R2) {
        double distancia_inicial = sqrt(pow(Xi - Xf, 2) + pow(Yi - Yf, 2));
        
        double dist_fuga = Vi * 1.5;

        double distancia_apos_fuga = distancia_inicial + dist_fuga;

        if (distancia_apos_fuga <= R1 + R2)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }


}
