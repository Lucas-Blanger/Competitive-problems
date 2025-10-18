#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        double total = 0.0;
        int m;
        cin >> m;
        vector<pair<string, double>> orti(m);

        for(int j = 0; j < m; j++){
            cin >> orti[j].first >> orti[j].second;
        }

        int p;
        cin >> p;
        vector<pair<string, double>> comprar(p);

        for(int y = 0; y < p; y++){
            cin >> comprar[y].first >> comprar[y].second;
            for(int z = 0; z < m; z++){
                if(comprar[y].first == orti[z].first){
                    total += orti[z].second * comprar[y].second;
                    break;
                }
            }
        }

        cout << fixed << setprecision(2);
        cout << "R$ " << total << endl;
        
    }
}