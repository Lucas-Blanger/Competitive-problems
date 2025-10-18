#include <bits/stdc++.h>

using namespace std;


int main(){
    int caso = 0;
    while (true)
    {
        int n,q;
        cin >> n >> q;
        if(n == 0 && q == 0) break;
        caso++;

        vector<int> numeros(n);
        vector<int> tentativas(q);

        for(int i = 0; i< n;i++){
            cin >> numeros[i];
        }

        sort(numeros.begin(), numeros.end());

        for(int i = 0; i< q;i++){
            cin >> tentativas[i];
        }

        cout << "CASE# " << caso << ":" << endl;

        for(int i = 0; i< q;i++){

            auto p = find(numeros.begin(), numeros.end(), tentativas[i]);

            if(p != numeros.end()){
                cout << tentativas[i] << " found at " << distance(numeros.begin(), p) + 1 << endl;
            }else{
                cout << tentativas[i] << " not found" << endl;
            }

        }

        


        
    }
    
}