#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    cin.ignore();
    for(int i = 0; i < n; i++){
        string nome, sobrenome;
        getline(cin, nome);
        getline(cin, sobrenome);
        

        string r = "";
        int y = 0;

        int nomeT = nome.size();
        int sobrenomeT = sobrenome.size();

        while(y < nomeT){
            r += nome[y];
            if(y+1 < nomeT) r += nome[y+1];
            r += sobrenome[y];
            if(y+1 < sobrenomeT) r += sobrenome[y+1];
            y +=2;
        }
        
        cout << r << endl;
    }
}