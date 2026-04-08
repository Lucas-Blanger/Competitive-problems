#include <bits/stdc++.h>
using namespace std;


int main(){
    while(true){
        int n,c,k;
        cin >> n >> c >> k;
        if(n== 0 &&c==0&&k==0) break;


        map<int,long long int> num;

        for(int i = 1; i <= k; i++){
            num[i] = 0;
        }
        for(int i = 0; i < n;i++){
            for(int j = 0; j < c; j++){
                int aux;
                cin >> aux;
                num[aux]++;
            }
        }

        long long int first = INT_MAX;
        for (auto p : num) {
            first = min(first, p.second);
        }

        bool espace = false;
        for (auto p : num) {
            if(p.second == first){
                if(espace) cout << " ";
                cout << p.first;
                espace = true;
            }
        }
        cout << endl;

    }
    
}