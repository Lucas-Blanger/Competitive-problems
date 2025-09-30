#include <bits/stdc++.h>

using namespace std;

int main(){
    while(true){
        int h1,m1,h2,m2;
        cin >> h1>>m1>>h2>>m2;

        if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) break;

        int minutosI = 0, minutosF = 0;
        minutosI = h1 * 60 + m1;
        minutosF = h2 * 60 + m2;
        int dif;
        if(minutosI < minutosF){
            dif = minutosF - minutosI;
        }else {
            int aux = (24*60) - minutosI;
            dif = aux + minutosF;
        }


        cout << dif << endl;
    }
}