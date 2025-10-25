#include <bits/stdc++.h>

using namespace std;

int main(){
    string risada;
    cin >> risada;

    string nova = "";

    for(int i = 0; i < risada.size(); i++){
        if(risada[i] == 'a') nova += 'a';
        else if(risada[i] == 'e') nova += 'e';
        else if(risada[i] == 'i') nova += 'i';
        else if(risada[i] == 'o') nova += 'o';
        else if(risada[i] == 'u') nova += 'u';
    }

    string contra = "";

    for(int i = nova.size()-1; i >= 0; i--){
        contra += nova[i];
    }

    if(contra == nova) cout << 'S' << endl;
    else cout << 'N' << endl;

    



}