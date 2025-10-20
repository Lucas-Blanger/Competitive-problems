#include <bits/stdc++.h>

using namespace std;


int main(){

    unsigned long long m, n;
    while(cin >> m >> n){
        bitset<32> a(m);
        bitset<32> b(n);
        bitset<32> r;

        // é um xor
        for(int i = 0; i < 32; i++){
           r[i] = a[i] ^ b[i];
        }
        cout << r.to_ulong() << endl;;

    }
    
}
    