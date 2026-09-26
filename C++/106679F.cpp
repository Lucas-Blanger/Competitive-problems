#include <bits/stdc++.h>


using namespace std;

const long long MAXN = 1e7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    vector<long long> flor(n+1);
    vector<long long> aux(MAXN+MAXN,0);

    long long resto = -1;

    flor[1] = 2;
    aux[2] = 1;
    flor[2] = 3;
    aux[3] = 2;

    resto = 3;
    for(long long i = 3; i <= n;i++){
        if(aux[i] == 0){
            resto++;
            flor[i] = resto;
            aux[resto] = i;
        }else{
            flor[i] = aux[i] * 3;
            resto = flor[i];
            aux[aux[i]*3] = i;
        }

    }


    cout << flor[n] << "\n";
}