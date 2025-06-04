#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int PA, PB;
        long double G1, G2;
        cin >> PA >> PB >> G1 >> G2;

        int anos = 0;

        while (PA <= PB && anos <= 100) {
            PA += (int)(PA * (G1 / 100.0));
            PB += (int)(PB * (G2 / 100.0));
            anos++;
        }

        if (anos > 100) {
            cout << "Mais de 1 seculo." << endl;
        } else {
            cout << anos << " anos." << endl;
        }
    }

    return 0;
}
