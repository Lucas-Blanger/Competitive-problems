#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){
    long long m, total, pot;
    int qbits;
    cin >> m;

    total = m * 8LL * 1000000LL;
    pot = 1;

    qbits = 0;

    while (pot < total)
    {
      pot *= 2;
      qbits++;
    }
    cout << qbits << endl;
    

    
}