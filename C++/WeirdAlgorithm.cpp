#include <bits/stdc++.h>

using namespace std;


int main(){
    long long n;
    cin >> n;
    long long cont = 0;
    if(n != 1) cout << n << " ";
    else cout << n << endl;
    while(n != 1){
        if(n % 2 != 0){
            n = (n * 3) + 1;
        }else{
            n = n / 2;
        }
        if(n != 1) cout << n << " ";
        else cout << n << endl;
    }
}