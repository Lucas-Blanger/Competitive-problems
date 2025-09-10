#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;

    while(cin >> n){
        vector<int> lar(n);
        vector<int> cheg(n);
        vector<int> novo(n);
        // unordered_map<int, int> lar;
        // unordered_map<int, int> cheg;
        for(int i = 0; i < n; i++){
            cin >> lar[i];
            novo[i] = lar[i];
        }
        for(int i = 0; i < n; i++){
            cin >> cheg[i];
        }

        int ultra = 0;

        unordered_map<int, int> posFinal;
        for (int i = 0; i < n; i++) posFinal[cheg[i]] = i;

        vector<int> v(n);
        for (int i = 0; i < n; i++) v[i] = posFinal[lar[i]];

  
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (v[i] > v[j]) ultra++;
            }
        }
                   
        cout << ultra << endl;
    
            
    }

    


}