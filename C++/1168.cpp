#include <iostream>
#include <string>
using namespace std;

int main() {
    int casos;
    cin >> casos;
    string valor;

    int ledsPorNumero[10] = {6,2,5,5,4,5,6,3,7,6};

    while (casos--) {
        cin >> valor;
        int totalLeds = 0;

        for (char c : valor) {
            totalLeds += ledsPorNumero[c - '0'];
        }

        cout << totalLeds << " leds" << endl;
    }

    return 0;
}
