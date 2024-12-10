#include <iostream>
using namespace std;

int calcularMDC(int a, int b) {
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        int F1, F2; 
        cin >> F1 >> F2;
        
        cout << calcularMDC(F1, F2) << endl;
    }

    return 0;
}
