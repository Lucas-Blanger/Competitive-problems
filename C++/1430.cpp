#include <bits/stdc++.h>


using namespace std;

int main(){

    while(true){
        string linha;
        cin >> linha;
        if(linha == "*") break;
        string aux = "";
        int r = 0;
        map<char, double> notas;

        notas['W'] = 1.0;
        notas['H'] = 0.5;
        notas['Q'] = 0.25;
        notas['E'] = 0.125;
        notas['S'] = 0.0625;
        notas['T'] = 0.03125;
        notas['X'] = 0.015625;

        for(int i = 1; i < linha.size(); i++){
            if(linha[i] == '/'){
                double cont = 0;
                for(int j = 0; j < aux.size(); j++){
                    cont += notas[aux[j]];
                }
                if(cont == 1.0) r++;
       
                aux = "";
            }else{
                aux += linha[i];
            }

        }
        cout << r << endl;

    }

}