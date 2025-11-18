#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string linha;
        cin >> linha;
        stack<char> pilha;

        int diamantes = 0;
        for(int j=0; j < linha.size(); j++){
            if(linha[j] != '.'){
                if(pilha.empty()){
                    pilha.push(linha[j]);
                }else{
                    if(pilha.top() == '<' && linha[j] == '>') {
                        diamantes++;
                        pilha.pop();
                    }else{
                        pilha.push(linha[j]);
                    }
                }
            }
        }
        cout << diamantes << endl;
    

       
    }
}