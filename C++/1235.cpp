#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;


int main(){
    int n;
    cin >> n;

    cin.ignore();
    for(int i = 0; i < n; i++){
        string linha;
        getline(cin, linha);

        int meio = linha.size() / 2;

        string nova = "";

        for(int i = meio-1; i >= 0; i--){
            nova += linha[i];
        }
        for(int i = linha.size()-1; i >= meio; i--){
            nova += linha[i];
        }

        cout << nova << endl;
    }
   
}