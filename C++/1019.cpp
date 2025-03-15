#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <cmath>

using namespace std;

int main(){
    int n, h, m, s, resto;
    cin >> n;
    h = (n / 60) / 60;
    resto = n - ((h * 60) * 60);
    m = resto / 60;
    resto = n - (((h * 60) *60) + (m *60));
    s = resto;
    cout << h << ":" << m << ":" << s << endl;
    
}