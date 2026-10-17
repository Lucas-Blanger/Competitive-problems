#include <bits/stdc++.h>


using namespace std;


int main(){
    int a,g;

    cin >> a >> g;

    if(a > g){
        cout << "Andre ficou com a laranja\n"; 
    }else if(g > a){
        cout << "Gabriel ficou com a laranja\n";
    }else{
        if(a % 2 == 0){
            cout << "Andre ficou com a laranja\n"; 
        }else cout << "Gabriel ficou com a laranja\n";
    }

}