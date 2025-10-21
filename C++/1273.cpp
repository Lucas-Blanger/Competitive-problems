#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;


int main(){
    
    int aux = 0;

    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        aux++;
        string nomes[n];
        int maior = 0;
        if(aux != 1) cout << endl;

        for(int i = 0; i < n; i++){
            cin >> nomes[i];
            if(nomes[i].size() > maior) maior = nomes[i].size();
        
        }
        for(int i = 0; i < n; i++){
            cout << setw(maior) << nomes[i] << endl;
        }

        


    }
   
}