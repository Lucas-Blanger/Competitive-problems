#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,r;
    while(cin >> n >> r){
        vector<int> m(r);
        for(int i = 0; i < r; i++){
            cin >> m[i];
        }
        sort(m.begin(), m.end());
        bool aux = false;
        bool ver = false;
        for(int i = 1; i <= n; i++){
            aux = false;
            
            for(int j = 0; j < r; j++){
                if(m[j] == i){
                    aux = true;
                }
            }
            if(aux == false && i == n){
                cout << i << " ";
                ver = true;
            }else if(aux == false){
                cout << i << " ";
                ver = true;
            }
        }
        if(ver == false) cout << '*';
        cout << endl;
        
    }
}