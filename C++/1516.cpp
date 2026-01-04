#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;

    while(true){
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        vector<string> ma(n);
        for(int i = 0; i < n; i++){
            string aux;
            cin >> aux;
            ma[i] = aux;
        }

        int a,b;
        cin >> a >> b;

        int an = a/n;
        int bm = b/m;

       for(int i = 0; i < n; i++){
            string nova = "";

            string aux = ma[i];
            
            for(int j = 0 ; j < aux.size(); j++){
                char delta = aux[j];
                for(int y = 0; y < bm; y++){
                    nova += delta;
                }
            }

            for(int j = 0; j < an; j++){
                cout << nova << endl;
            }

        }
        cout << endl;

    }
}