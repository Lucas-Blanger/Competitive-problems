#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int c,g;
    cin >> c >> g;
    if (c == 1) {
        cout << "vivo e morto" << endl;
    } else {
        if (g == 1) {
            cout << "vivo" << endl;
        } else {
            cout << "morto" << endl;
        }
    }
}