#include<bits/stdc++.h>


using namespace std;


int main(){
    int  n;
    cin >> n;


    for(int i = 0; i < n; i++){
        int t;
        cin >> t;

        int cont = 0;

        vector<int> trens;
        for(int j = 0; j < t; j++){
            int aux;
            cin >> aux;
            trens.push_back(aux);
        }

        for(int x = 0; x < t-1; x++){
            for(int y = x+1; y < t; y++){
                if(trens[x] > trens[y]){
                    cont++;
                    int aux = trens[x];
                    trens[x] = trens[y];
                    trens[y] = aux;
                }
            }
        }
        cout << "Optimal train swapping takes " << cont << " swaps."<< endl;
    
    }
}