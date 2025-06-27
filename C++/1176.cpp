#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;


int main () {
    int t, n;
    cin >> t;
    unsigned long long fib[61];

    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i <= 60; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    for(int i = 0; i < t; i++){
        cin >> n;
        cout << "Fib(" << n << ") = " << fib[n] << endl;
    }

}
    





