#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, l ,c;

    while(cin >> n >> l >> c){
        cin.ignore();
        string texto;
        getline(cin, texto);

        //vector<int> aux(n);

 

        int linhas = 1;           
        int caractere = 0;         

        string palavra;
        stringstream ss(texto);

        while (ss >> palavra) {
            int len = palavra.size();

            if (caractere == 0) {
                caractere = len;
            } else if (caractere + 1 + len <= c) {
                caractere += 1 + len;
            } else {
                linhas++;
                caractere = len;
            }
        }

        double r = double(linhas) / double(l);
        cout << ceil(r) << endl;
  

    }
}