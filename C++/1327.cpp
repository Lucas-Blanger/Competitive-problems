#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;

        vector<string> nomes;
        vector<int> bar;
        vector<bool> ativo(n, true);
        int topo = 0;

        for(int i = 0; i < n; i++){
            string nome;
            cin >> nome;
            nomes.push_back(nome);
        }

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 13; j++){
                int x;
                cin >> x;
                bar.push_back(x);
            }
        }

        while(true){
            int total = 0;
            for(int i = 0; i < n; i++)
                if(ativo[i]) total++;

            vector<pair<int,int>> rodada;
            for(int i = 0; i < n; i++){
                if(ativo[i]){
                    if(topo == 52) break;
                    rodada.push_back({bar[topo], i});
                    topo++;
                }
            }

            if((int)rodada.size() < total) break;

            int menor = INT_MAX;
            for(auto x : rodada)
                menor = min(menor, x.first);

            for(auto x : rodada)
                if(x.first == menor)
                    ativo[x.second] = false;

            int vivos = 0;
            for(int i = 0; i < n; i++)
                if(ativo[i]) vivos++;

            if(vivos <= 1) break;
        }

        for(int i = 0; i < n; i++)
            if(ativo[i]) cout << nomes[i] << " ";
        cout << endl;
    }
}