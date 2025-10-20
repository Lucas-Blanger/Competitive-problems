#include <bits/stdc++.h>

using namespace std;


int main(){
    int n; 
    cin >> n;

    cin.ignore();
    for(int i = 0; i < n; i++){
        string linha;
        getline(cin, linha);

        stringstream ss(linha);
        set<string> lista;

        string palavra;
        while(ss >> palavra){
            lista.insert(palavra);
        }

        int t = lista.size();
        int cont = 0;
        for(auto x:lista){
            if(cont == t - 1){
                cout << x << endl;
                cont++;
            }else{
                cout << x << " ";
                cont++;
            }
        }
        
    }
}
    