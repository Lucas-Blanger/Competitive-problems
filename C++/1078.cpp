#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= 10;i++){
        cout << i << " x " << n << " = " << i*n << endl;
    }
}