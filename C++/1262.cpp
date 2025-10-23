#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;

    while(cin >> s){
        int p;
        cin >> p;
        int ciclos = 0;

        int cont = 0;
        for(int i = 0; i < s.size(); i++){
            if(cont == p){
                ciclos++;
                cont = 0;
            }
           if(s[i] == 'W'){
                ciclos++;
                if(cont != 0){
                    ciclos++;
                    cont = 0;
                }
           }else {
                if(s[i] == 'R'){
                    cont++;
                }
               
           }


        }
        if(cont != 0){
            ciclos++;
            cont = 0;
        }

        cout << ciclos << endl;
    }

}
