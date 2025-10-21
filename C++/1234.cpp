#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){
    string linha;
    while(getline(cin,linha)){
        char aux = 'U';
        for(int i = 0; i < linha.size(); i++){
            if(isalpha(linha[i])){
                if(aux == 'U'){
                    linha[i] = toupper(linha[i]);
                    aux = 'L';
                }else{
                    linha[i] = tolower(linha[i]);
                    aux = 'U';
                }

            }
        }    
        cout << linha << endl;
    
    }
}