
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dia1,dia2;
    int h1,m1,s1,h2,m2,s2;

    string lixo;
    cin >> lixo >> dia1;
    char caca;
    cin >> h1 >> caca >> m1 >> caca >> s1;

    cin >> lixo >> dia2;
    cin >> h2 >> caca >> m2 >> caca >> s2;

    int inicio = dia1 * 86400 + h1 * 3600 + m1 * 60 + s1;
    int fim = dia2 * 86400 + h2 * 3600 + m2 * 60 + s2;

    int total = fim - inicio;

    int rd,rh,rm,rs;

    rd = total / (24*60*60);

    total = total - (rd * 24 * 60 * 60);

    rh = total / (60*60);

    total = total - (rh * 60*60);

    rm = total / (60);

    total = total - (rm*60);

    rs = total;

    cout << rd<< " dia(s)" << endl;
    cout << rh<< " hora(s)" << endl;
    cout << rm<< " minuto(s)" << endl;
    cout << rs<< " segundo(s)" << endl;

   
}