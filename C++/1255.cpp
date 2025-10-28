#include <bits/stdc++.h>


using namespace std;


int main(){
    int n;
    cin >> n;

    cin.ignore();
    for(int i = 0; i < n; i++){
        map<char, int> aux;
        string texto;
        getline(cin, texto);

        for(int j = 0; j < texto.size(); j++){ 
            if(isalpha(texto[j])){
                aux[tolower(texto[j])]++;
            }

        }

        int maior = 0;
        vector<char> r;

        for(auto p:aux){
            if(p.second > maior){
                r.clear();
                r.push_back(p.first);
                maior = p.second;
            }else if(p.second == maior){
                r.push_back(p.first);
            }
        }

        sort(r.begin(), r.end());

        for(int j = 0; j < r.size(); j++){
            cout << r[j];
        }
        cout << endl;

    }
}