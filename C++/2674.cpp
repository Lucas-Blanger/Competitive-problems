#include <bits/stdc++.h>

using namespace std;

bool ehPrimo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}


int main(){

    string n;
    while(cin >> n){

        bool pass = true;
        for(int i = 0; i < n.size(); i++){
            int num = n[i] - '0';
            if(!ehPrimo(num)) pass = false;
        }

        bool aux = ehPrimo(stoi(n));
        if(aux && pass) {
            cout << "Super" << endl;
        } else if(aux && !pass) {
            cout << "Primo" << endl;
        }else{
            cout << "Nada" << endl;
        }
            
    }
}