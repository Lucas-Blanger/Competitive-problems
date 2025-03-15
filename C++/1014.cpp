#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <cmath>

using namespace std;

int main(){
    int x;
    double y, r;
    cin >> x;
    cin >> y;
    r = x / y;
    cout << fixed << setprecision(3);
    cout << r << " km/l" << endl;
}