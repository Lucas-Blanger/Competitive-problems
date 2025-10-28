#include <bits/stdc++.h>

using namespace std;


int main(){
    string linha;
    while(getline(cin,linha)){
        set<char> letras;
        if(linha == "") {
            cout << endl;
            continue;
        }

        for(int i = 0; i < linha.size(); i++){
            if(isalpha(linha[i]) && linha[i] != ' ') letras.insert(linha[i]);
        }
        vector<char> letrasOrdenadas(letras.begin(), letras.end());
        
        vector<string> faixas;

        int i = 0;
        
        while(i < letrasOrdenadas.size()){
            char inicio = letrasOrdenadas[i];
            char fim = letrasOrdenadas[i];
            
            
            while(i + 1 < letrasOrdenadas.size() && letrasOrdenadas[i + 1] == letrasOrdenadas[i] + 1){
                i++;
                fim = letrasOrdenadas[i];
            }
            
            
            string faixa = "";
            faixa += inicio;
            faixa += ':';
            faixa += fim;
            faixas.push_back(faixa);
            
            i++;
        }
        
        for(int j = 0; j < faixas.size(); j++){
            cout << faixas[j];
            if(j < faixas.size() - 1){
                cout << ", ";
            }
        }
        cout << endl;
        
        
    
    }
}