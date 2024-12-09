#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int n;
    double resultado;

    cin >> n;

    resultado = (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5);
    cout << fixed << setprecision(1) << resultado << endl;

    return 0;
}
