#include <bits/stdc++.h>

using namespace std;

int main(){
    double a, b;
    cin >>a >> b;

    

    double r = ((1+(a/100))*(1+(b/100))-1) * 100;

    cout << fixed << setprecision(6);
    cout << r << endl;


}