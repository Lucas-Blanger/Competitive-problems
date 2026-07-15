#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int a,b,c;
    cin >> a >> b >> c;

    char aux;
    cin >> aux;

    //3 questões de grafos custam o mesmo que 2 questões de programação dinâmica;
    //2 questões de geometria custam o mesmo que 5 questões de grafos.

    long long total = 2*a + 3*b + 5*c;

    if(aux == 'A') {
        cout << total / 2 << '\n';
    } 
    else if(aux == 'B') {
        cout << total / 3 << '\n';
    } 
    else {
        cout << total / 5 << '\n';
    }

}