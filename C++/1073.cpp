#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n;
    long int pot;
    cin >> n;

    cout << fixed << setprecision(2);
    for(int i = 2; i <= n; i+=2){
        pot = pow(i,2);
        cout << i << "^" << "2" << " = " << pot << endl;
    }
}