#include <bits/stdc++.h>

using namespace std;

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int main(){
    long long int n;
    while(true){
        cin >> n;
        if(n==0) break;

        map<long long int,char> mapa;

        for(long long int i = 1; i <= n; i++){
            mapa[i] = 'F';
        }
        

        for(long long int i = 1; i <= n; i++){
            for(long long int j = i; j <= n; j++){
                if(j % i == 0){
                    if(mapa[j] == 'F') mapa[j] = 'A';
                    else mapa[j] = 'F';
                }
            }
        }

        bool first = true;
        for(auto& p : mapa) {
            if(p.second == 'A'){
                if(first){
                    cout << p.first;
                    first = false;
                }else cout << " " << p.first;
                
            } 

        }
        cout << endl;
    }
}