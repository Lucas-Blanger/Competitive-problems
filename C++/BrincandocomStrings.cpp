#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
    string frase;
    vector<char> n;
    cin >> frase;

    int t = frase.size();

    for(int i = 0; i < t; i++){
        if(frase[i] == 'A' || frase[i] == 'O' || frase[i] == 'Y' || frase[i] == 'E' || frase[i] == 'U' || frase[i] == 'I' || frase[i] == 'a' || frase[i] == 'o' || frase[i] == 'y' || frase[i] == 'e' || frase[i] == 'u' || frase[i] == 'i'){
            continue;
        }else{
            frase[i] = tolower(frase[i]);
            n.push_back('.');
            n.push_back(frase[i]);   
        }
    }

    for(int i = 0; i < n.size(); i++){
        cout << n[i];
    }
    cout << endl;


}