#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    string palavras[n];
    string r[n];

    for(int i = 0; i < n; i++){
        cin >> palavras[i];
    }

    for(int i = 0; i < n; i++){
        string palavra = palavras[i];

        if(palavra.size() == 3){
            if(palavra[0] == 'O' && palavra[1] == 'B'){
                r[i] = "OBI";
            }else if(palavra[0] == 'U' && palavra[1] == 'R'){
                r[i] = "URI";
            }else{
                r[i] = palavra;
            }
        }else{
            r[i] = palavra;
        }
    }
    for(int i = 0; i < n; i++){
        if(i == n-1) cout << r[i] << endl;
        else cout << r[i] << ' ';
    }


    



}