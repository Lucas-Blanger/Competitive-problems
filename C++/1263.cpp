#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;


int main(){
    string linha;
    while(getline(cin,linha)){
        stringstream ss(linha);

        vector<string> palavras;
        string palavra;
        while(ss >> palavra){
            palavras.push_back(palavra);
        }

        int cont = 0;
        bool pass = false;
        for(int i = 1; i < palavras.size(); i++){
            string aux = palavras[i-1];
            string aux2 = palavras[i];
            if(pass){
                if(tolower(aux[0]) == tolower(aux2[0])){
                    pass = true;
                }else{
                    pass = false;
                }
            }else{
                if(tolower(aux[0]) == tolower(aux2[0])){
                    cont++;
                    pass = true;
                }

            }
            
        }
        cout << cont << endl;
    }
}