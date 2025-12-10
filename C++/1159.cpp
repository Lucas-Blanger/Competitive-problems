#include <bits/stdc++.h>


using namespace std;


int main(){
    int x; 
    while(true){
        cin >> x;
        if(x == 0) break;

        int cont = 0, soma = 0;

        while(cont != 5){
            if(x % 2 == 0){
                cont++;
                soma += x;
            }
            x++;
        }
        cout << soma << endl;
    }
}