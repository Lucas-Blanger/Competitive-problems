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
    cout << fixed << setprecision(1);
    for(int i = 0; i < n; i++){
        double a, b, c, r;
        cin >> a >> b >> c;
        r = ((a*2) + (b*3) + (c*5)) / 10.0;
        cout << r << endl;
    }

}