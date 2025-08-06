#include <iostream>


using namespace std;

int main(){

    int c;
    cin >> c;
    int maior = 100;
    int maiorFinal = 100;
    for(int i = 0; i < c; i++){
        int v;
        cin >> v;
        maior += (v);
        if(maior > maiorFinal){
            maiorFinal = maior;
        }
    }

    cout << maiorFinal << endl;

}