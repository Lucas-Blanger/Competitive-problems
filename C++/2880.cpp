#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string texto, cifra;
    cin >> texto;
    cin >> cifra;

    int cont = 0;
    bool pass = true;
    for(int i = 0; i <= texto.size() - cifra.size(); i++){
        pass = true;
        for(int j = i, k = 0; k < cifra.size(); j++, k++){
            if(texto[j] == cifra[k]){
                pass = false;
            }
            //cout << texto[j] << " " << cifra[k] << endl;
        }
        if(pass){
            cont++;
        }
        //cout << endl;
    }
    cout << cont << endl;
  




   
}
