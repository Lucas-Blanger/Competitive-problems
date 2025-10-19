#include <bits/stdc++.h>

using namespace std;


int main() {
    map<string, bool> livro;
    string linha;
    
    while(getline(cin, linha)) {  
        string palavra = "";
        
        for(char c : linha) {
            if(isalpha(c)) {
                palavra += tolower(c);
            } else {
                if(!palavra.empty()) {
                    livro[palavra] = true;
                    palavra = "";
                }
            }
        }
        
        if(!palavra.empty()) {
            livro[palavra] = true;
        }
    }
    
    for(auto& p : livro) {
        cout << p.first << endl;
    }
    
}