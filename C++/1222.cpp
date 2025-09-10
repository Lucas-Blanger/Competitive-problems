#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, l ,c;

    while(cin >> n >> l >> c){
        cin.ignore();
        string texto;
        getline(cin, texto);

        //vector<int> aux(n);

 

        int linhas = 1, caractere = c;

        string palavra;
        stringstream ss(texto);
        while (ss >> palavra) {
            if(palavra.size() + 1 <= caractere){
                caractere -= (palavra.size() + 1);
            }else if(palavra.size() <= caractere){
                caractere -= (palavra.size());
            }else{
                linhas++;
                caractere = c;
                if(palavra.size() == caractere){
                    caractere -= palavra.size();
                }else{
                    caractere -=  (palavra.size() + 1);
                }

            }
        }

        double r = double(linhas) / double(l);
        cout << ceil(r) << endl;
  

    }
}