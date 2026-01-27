#include <bits/stdc++.h>


using namespace std;

int main(){
    string linha;
    while(getline(cin,linha)){
        bool it = false;
        bool b = false;
        for(int i = 0; i < linha.size(); i++){
            if(linha[i] == '*'){
                if(it == true) {
                    cout << "</b>";
                    it = false;
                }else{
                    cout << "<b>";
                    it = true;
                }
            } else if(linha[i] == '_'){
                if(b == true) {
                    cout << "</i>";
                    b = false;
                }else{
                    cout << "<i>";
                    b = true;
                }
            }else{
                cout << linha[i];
            }
        }
        cout << endl;
    }
   

}