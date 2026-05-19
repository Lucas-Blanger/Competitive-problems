#include <bits/stdc++.h>



using namespace std;



int main() {
    string nome;
    int q;
    while(cin >> nome >> q){
        vector<tuple<string, double, int>> lista;
        string pre;
        double valor;
        int pref;

        for(int i = 0; i < q; i++){
            cin.ignore();
            getline(cin, pre);
            cin >> valor >> pref;
            lista.push_back(make_tuple(pre, valor, pref));

        }

        sort(lista.begin(), lista.end(), [](const auto& a, const auto& b) {
            if(get<2>(a) != get<2>(b))  
                return get<2>(a) > get<2>(b); 
            if(get<1>(a) != get<1>(b)) 
                return get<1>(a) < get<1>(b); 
            
            return get<0>(a) < get<0>(b);  // Senão, ordena por altura decrescente
        });

        cout << "Lista de " << nome << endl;
        cout << fixed << setprecision(2);
        for(int i = 0; i < q;i++){
            cout <<  get<0>(lista[i]) << " - R$" << get<1>(lista[i]) << endl;

        }
        cout << endl;




    }

}