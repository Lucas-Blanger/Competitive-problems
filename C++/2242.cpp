#include <bits/stdc++.h>

using namespace std;

int main(){
    string riso;

    cin >> riso;
    string novoriso = "";
    string risocopia;

    for(int i = 0; i < riso.size(); i++){
        if(riso[i] == 'a' || riso[i] == 'e' || riso[i] == 'i' || riso[i] == 'o' || riso[i] == 'u'){
            novoriso += riso[i];
        }
    }
    risocopia = novoriso;
    reverse(risocopia.begin(), risocopia.end());

    bool pass = true;

    for(int i = 0; i < novoriso.size();i++){
        if(novoriso[i] != risocopia[i]){
            pass = false;
        }
    }

    if(pass){
        cout << 'S' << endl;
    }else {
        cout << 'N' << endl;
    }



}