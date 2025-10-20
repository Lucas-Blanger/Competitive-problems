#include <bits/stdc++.h>

using namespace std;


int main(){
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0) break;

        unordered_map<string, string> original;

        for(int i = 0; i < n; i++){
            string nome, assinatura;
            cin >> nome >> assinatura;
            original[nome] = assinatura;
        }

        int total = 0;
        int m;
        cin >> m;
        unordered_map<string, string> aula;
        for(int i = 0; i < m; i++){
            string nome, assinatura;
            cin >> nome >> assinatura;
            aula[nome] = assinatura;

            string nomeOriginal = original[nome];
            int dif = 0;
            if(nomeOriginal.size() != assinatura.size()){
                total++;
            }else{
                for(int j = 0; j < assinatura.size(); j++){
                    if(nomeOriginal[j] != assinatura[j]) {
                        dif++;
                    }
                }
                if(dif > 1) total++;

            }
           
        }

       



    
        cout << total << endl;
    }
    
}
    