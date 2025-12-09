#include <bits/stdc++.h>



using namespace std;

int main() {
    int g, p;


    while(true){
        cin >> g >> p;
        if(g == 0 && p == 0) break;
        
        vector<vector<int>> races(g, vector<int>(p, 0));
        for(int i = 0; i < g; i++){
            for(int j = 0; j < p; j++){
                cin >> races[i][j];
            }
        }
        
        int s;
        cin >> s;
        
        for(int sys = 0; sys < s; sys++){
            int k;
            cin >> k;
            
            vector<int> pontos(k);
            for(int i = 0; i < k; i++){
                cin >> pontos[i];
            }
            
            map<int, int> vrau; 
            
            for(int i = 0; i < g; i++){
                for(int piloto = 1; piloto <= p; piloto++){
                    int posicao = races[i][piloto-1]; 
                    
                    if(posicao >= 1 && posicao <= k){
                        vrau[piloto] += pontos[posicao-1];
                    }
                }
            }
            
            int maxP = 0;
            for(auto& par : vrau){
                maxP = max(maxP, par.second);
            }
            
            vector<int> win;
            for(auto& par : vrau){
                if(par.second == maxP){
                    win.push_back(par.first);
                }
            }
            
            sort(win.begin(), win.end());
            
            for(int i = 0; i < win.size(); i++){
                if(i > 0) cout << " ";
                cout << win[i];
            }
            cout << endl;
        }
    }
    

}