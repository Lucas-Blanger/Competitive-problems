#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++ ){
        int m;
        cin >> m;
        vector<int> v(m);
        vector<int> aux(m);

        for(int j = 0; j < m; j++){
            cin >> v[j];
            aux.push_back(v[j]);
        }

        int total = 0;

        sort(aux.begin(), aux.end(), greater<int>());
        
        
        for(int j = 0; j < m; j++){
           if(v[j] == aux[j]) total++;
        }

        cout << total << endl;


    }
    
}