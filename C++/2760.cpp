#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){

    string a, b, c;

    getline(cin, a);
    getline(cin, b);
    getline(cin, c);

    cout << a << b << c << endl;
    cout << b << c << a << endl;
    cout << c << a << b << endl;

    cout << a.substr(0, 10) << b.substr(0, 10) << c.substr(0, 10) << endl;

}