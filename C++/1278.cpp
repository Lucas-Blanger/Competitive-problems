#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    int y = 0;
    while (true){
        int n;
        cin >> n;
        if(n == 0) break;
        y++;
        if(y != 1) cout << endl;

        string texto[n];
        string nova[n];

        cin.ignore();
        for(int i = 0; i < n; i++){
            string linha;
            getline(cin, linha);
            texto[i] = linha;
        }
        
        int maior = 0;

        for(int i = 0; i < n; i++){
           stringstream ss(texto[i]);
           string palavra, aux = "";
           while (ss >> palavra){
                aux += palavra;
                aux += ' ';
           }
           aux.pop_back();
           if(aux.size() > maior) maior = aux.size();
           nova[i] = aux;
        }

         for(int i = 0; i < n; i++){
            int espacos = maior - nova[i].size();
            for(int j = 0; j < espacos; j++){
                cout << " ";
            }
            cout << nova[i] << endl;
        }

    }
    
    
}