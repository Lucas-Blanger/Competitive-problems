#include <bits/stdc++.h>

using namespace std;

struct pais{
    string nome;
    int ouro, prata, bronze;
};

bool ordena(pais a, pais b){
    if(a.ouro != b.ouro) return a.ouro > b.ouro;
    else if(a.prata != b.prata) return a.prata > b.prata;
    else if(a.bronze != b.bronze) return a.bronze > b.bronze;
    else return a.nome < b.nome;

}

int main() {

    int n;
    cin >> n;
    pais paises[n];

    for(int i = 0; i < n; i++){
        cin >> paises[i].nome >> paises[i].ouro >> paises[i].prata >> paises[i].bronze;
    }
    sort(paises, paises + n, ordena);

    for(int i = 0; i < n; i++){
        cout << paises[i].nome << " " << paises[i].ouro << " " << paises[i].prata << " " << paises[i].bronze << endl;
    }
    
}
