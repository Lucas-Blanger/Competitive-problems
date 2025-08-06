#include <bits/stdc++.h>

using namespace std;

int main(){
    string frase;
    cin >> frase;
    string nova = "";

    int ma = 0, mi = 0;

    for(int i = 0; i < frase.size(); i++){
        if(int(frase[i]) < 96){
            ma++;
        }else{
            mi++;
        }
    }
    if(mi >= ma){
        for(int i = 0; i < frase.size(); i++){
            nova += tolower(frase[i]);
        }
    } else {
        for(int i = 0; i < frase.size(); i++){
            nova += toupper(frase[i]);
        }
    }
    cout << nova << endl;


}