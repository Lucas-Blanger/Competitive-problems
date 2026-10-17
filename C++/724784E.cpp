#include <bits/stdc++.h>


using namespace std;


int main(){
    string s;
    cin >> s;

    //D = OBSTACULO DANO
    // C COGUMELO QUE CRESCE
    // E ESTRELA INVENCIVEL 5


    char altura = 'A';
    int in = 0;
    bool morreu = false;

    for(int i = 0; i < s.size(); i++){
        if(altura == 'B' && in == 0 && s[i] == 'D'){
            morreu = true;
            break;
        }else if(s[i] == 'D'){
            if(in > 0){
                in--;
            }else if(altura == 'A'){
                altura = 'B';
            }else{
                morreu = true;
                break;
            }
        }else if(s[i] =='C'){
            if(in > 0) in--;
            altura = 'A';
        }else if(s[i] == 'E'){
            if(in > 0) in--;
            in = 5;
        }
    }

    if(morreu) cout << "MORTO\n";
    else if(altura == 'A') cout << "ALTO\n";
    else if(altura == 'B') cout << "BAIXO\n";

}