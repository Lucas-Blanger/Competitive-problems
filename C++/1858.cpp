#include <bits/stdc++.h>
#define MAXN (int)(2e5 + 10)
using namespace std;



int main(){
    int n;
    cin >>  n;

    map<int, int> aux;

    for(int i = 0; i < n; i++){
        int y;
        cin >> y;
        aux[i] = y;
    }

    int menor = MAXN;
    int indice = MAXN;

    for(auto x: aux){
        if(x.second < menor){
            menor = x.second;
            indice = x.first;
        }else if(x.second == menor){
            if(x.first < indice){
                indice = x.first;
                menor = x.second;
            }
        }
    }

    indice++;
    cout << indice << endl;


}