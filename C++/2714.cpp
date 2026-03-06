#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    while(n--){
        string senha;
        cin >> senha;
        string ra = "";

        bool pass = true;
        if(senha[0] != 'R' || senha[1] != 'A'){
            pass = false;
        } else if(senha.size() != 20){
            pass = false;
        } else{
            
            bool aux = false;
            for(int i = 2; i < senha.size();i++){
                if(!isdigit(senha[i])){
                    pass = false;
                    break;
                }else{
                    if(senha[i] != '0' || aux) {
                        ra += senha[i];
                        aux = true;
                    }
                }

            }

        }
        if(pass) cout << ra << endl;
        else cout << "INVALID DATA" << endl;
    }

}