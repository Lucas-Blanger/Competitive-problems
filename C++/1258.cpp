#include <bits/stdc++.h>

using namespace std;


int main(){
    int y = 0;
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        y++;
       

        vector<tuple<string, char, string>> lista;

        
        for(int i = 0; i < n; i++){
            string nome, cor;
            char t;
            cin.ignore();
            getline(cin, nome);
            cin >> cor >> t;
            lista.push_back(make_tuple(cor, t, nome));
        }

        sort(lista.begin(), lista.end(), [](auto &a, auto &b) {
            if (get<0>(a) != get<0>(b)) 
                return get<0>(a) < get<0>(b);
            if (get<1>(a) != get<1>(b)) 
                return get<1>(a) > get<1>(b);
            return get<2>(a) < get<2>(b); 
        });

        if(y != 1) cout << endl;

        for(int i = 0; i < n; i++){
            cout << get<0>(lista[i]) << " " << get<1>(lista[i]) << " " << get<2>(lista[i]) << endl;
        }

        




    }


  
    
}