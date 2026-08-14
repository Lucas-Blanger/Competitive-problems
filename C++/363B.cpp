#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;

    vector<int> vet(n);

    for(int i = 0; i < n; i++) cin >> vet[i];

    int maiorSoma = INT_MAX;

    int cont = 0;
    int soma = 0;
    int r = -1;
    for(int i = 0, j = 0; i < n; i++){
        soma += vet[i];
        cont++;
        if(cont == k+1){
            soma -= vet[j];
            j++;
            cont--;
        }
        if(soma < maiorSoma && cont>=k) {
            maiorSoma = soma;
            r = j;
        }
        
        
    }
    cout << r +1 << endl;
}