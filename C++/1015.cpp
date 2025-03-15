#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <cmath>

using namespace std;

int main(){
    double x1, y1, x2, y2, d;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    d = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    cout << fixed << setprecision(4);
    cout << d << endl;
}