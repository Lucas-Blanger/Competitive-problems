#include <bits/stdc++.h>


using namespace std;

const long long MOD = 1e9 + 7; 

long long exp_rapida(long long a, long long b) {
    const long long MOD = 1e9 + 7;
    long long resultado = 1;
    a %= MOD; 
    
    while(b > 0) {
        if(b % 2 == 1) {
            resultado = (resultado * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    
    return resultado;
}



int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long a,b;
        cin >> a >> b;
        long long r = exp_rapida(a,b);

        cout << r << endl;

    }

}