#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>

using namespace std;

int main(){
    int inteiro;
    float real;
    char texto;

    string s;

    cin >> inteiro >> real >> texto >> ws;

    getline(cin, s);

    char c = '\t';

    cout << inteiro << fixed << real << texto << s << endl;

    cout << inteiro << c << real << c << texto << c << s << endl;

    printf("%10d%10.6f%10c", inteiro, real, texto);

    cout << right << setw(10) << s << endl;


}