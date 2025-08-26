#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int cont = 0;
    for(int i = 0; i < n; i++){
        int porta;
        cin >> porta;
        if(porta == 1){
            continue;
        }
        if(porta == 2){
            cont++;
        }
        if(porta == 3){
            cont++;
        }
    }

    cout << cont << endl;
}