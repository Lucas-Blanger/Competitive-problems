#include <bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin >> t;
    int casos = 0;

    for(int i = 0; i < t; i++){
        casos++;
        int m, n;
        cin >> m >> n;

        vector<tuple<string, int, int, double>> renas(m);

        for(int j = 0; j< m; j++){
            string nome;
            int idade, peso;
            double altura;
            cin >> nome >> peso >> idade >> altura;
            renas[j] = make_tuple(nome, peso, idade, altura);
        }


        sort(renas.begin(), renas.end(), [](const auto& a, const auto& b) {
            if (get<1>(a) != get<1>(b))  
                return get<1>(a) > get<1>(b); // maior peso
            if (get<2>(a) != get<2>(b))
                return get<2>(a) < get<2>(b); // menor idade
            if (get<3>(a) != get<3>(b))
                return get<3>(a) < get<3>(b); // menor altura
            return get<0>(a) < get<0>(b);     // nome em ordem alfabética
        });

        cout << "CENARIO {" << casos << "}" << endl;

        for(int y = 1; y <= n; y++){
            cout << y << " - " << get<0>(renas[y-1]) << endl;
        }



    }
}
    