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
        int total = 0, soma = 0;
        string aux;

        while(ss >> aux){
            bool pass = false, ponto = false;

            for(int i = 0; i < aux.size(); i++){
                if(i == aux.size() - 1){
                    if(isalpha(aux[i]) != 0 || aux[i] == '.'){
                        if(aux[i] == '.') ponto = true;
                    }else{
                        pass = true;
                    }
                }else{
                    if(isalpha(aux[i]) != 0){

                    }else{
                        pass = true;
                    }

                }
            }
            if(pass == false && ponto == true){
                soma += aux.size() -1;
                total++;
            }else if(pass == false){
                soma += aux.size();
                total++;
            }

        }

        
        if(soma == 0){
            cout << 250 << endl;
        }else{
            int media = soma / total;
            if(media <= 3 ) cout << 250 << endl;
            else if(media >= 4 && media <= 5) cout << 500 << endl;
            else if(media >= 6 ) cout << 1000 << endl;

        }
        
             

    }
}