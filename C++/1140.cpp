#include <bits/stdc++.h>

using namespace std;

int main(){
   while(true){
        string frase;
        getline(cin, frase);
        if(frase == "*") break;

        stringstream ss(frase);

        string palavra;
        char first;

        ss >> palavra;
        transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
        first = palavra[0];
        bool pass = true;
        while(ss >> palavra){
            transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
            if(palavra[0] != first){
                pass = false;
                break;
            }
        }
        if(pass){
            cout << "Y" << endl;
        }else{
            cout << "N" << endl;
        }
    }
}