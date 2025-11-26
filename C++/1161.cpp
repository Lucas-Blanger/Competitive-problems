#include<bits/stdc++.h>


using namespace std;


int main(){

    vector<long long int> fatoriais;
    fatoriais.push_back(1);

    for(int i = 1; i <= 20; i++){
        long long int aux = i * fatoriais[i-1];
        fatoriais.push_back(aux);
    }
    int n, m;
    while(cin >> n >> m){

        long long int soma = fatoriais[n] + fatoriais[m];
        cout << soma << endl;
    
        
    }
}