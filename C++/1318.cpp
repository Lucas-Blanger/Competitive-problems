#include <bits/stdc++.h>

using namespace std;


int main(){
    while(true){
        int n,m;
        cin >> n >> m;

        if(n == 0 && m == 0) break;

        vector<int> bilhetes(n,0);
        int total = 0;
        vector<int> pacot(m);

        for(int i = 0; i < m; i++){
            cin >> pacot[i];

            if(bilhetes[pacot[i]-1] == 0 ){
                bilhetes[pacot[i]-1] = 1;
            }else if(bilhetes[pacot[i]-1] == 1){
                total++;
                bilhetes[pacot[i]-1]++;
            }
        }

        cout << total << endl;

    }
    
}