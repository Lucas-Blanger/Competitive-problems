#include <bits/stdc++.h>

using namespace std;


int main(){
    
    string assassino, morto;

    map<string, int> lista;
    while(cin >> assassino >> morto){

        if(lista.find(morto) != lista.end()) {
            lista[morto] = -1;  
        }else{
            lista[morto] = -1;
        } 
        if(lista.find(assassino) != lista.end() && lista[assassino] != -1){
            lista[assassino]++;
        }else{
            if(lista[assassino] != -1){
                lista[assassino] = 1;
            }
        }
    }

    cout << "HALL OF MURDERERS" << endl;

    for(auto x:lista){
        if(x.second != -1) cout << x.first << " " << x.second << endl;

    }
}
    