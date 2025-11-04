#include <bits/stdc++.h>

using namespace std;


int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        map<string, string> assinatura;
        for(int i = 0; i < n; i++){
            string nome, ass;
            cin >> nome >> ass;
            assinatura[nome] = ass;

        }
        int m;
        cin >> m;
        int r = 0;
        for(int i = 0; i < m; i++){
            string nome, ass;
            cin >> nome >> ass;
            int aux = 0;
            for(int j = 0; j <assinatura[nome].size(); j++){
                if(assinatura[nome][j] != ass[j]) aux++;
            }
            if(aux > 1) r++;
        }
        cout << r << endl;

    }
}
    