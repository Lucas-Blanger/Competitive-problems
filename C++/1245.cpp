#include <bits/stdc++.h>

using namespace std;

int  main(){
    int n;
    while(cin >> n){
        vector<pair<int, char>> bots;
        for(int i = 0; i < n; i++){
            int t;
            char p;
            cin >> t >> p;
            bots.push_back(make_pair(t, p));
        }

        int certos = 0;
        for(int i = 0; i < n; i++){
            for(int j= i; j < n; j++){
                if((bots[i].second == 'D' && bots[j].second == 'E' && bots[i].first == bots[j].first ) || bots[i].second == 'E' && bots[j].second == 'D' && bots[i].first == bots[j].first ){
                    certos++;
                    if(bots[i].second == 'D' && bots[j].second == 'E'){
                        bots[i].second = 'Z';
                        bots[j].second = 'Y';
                    } else if(bots[i].second == 'E' && bots[j].second == 'D'){
                        bots[i].second = 'Z';
                        bots[j].second = 'Y';
                    }
                }
            }
        }

        cout << certos << endl;

        

    }
}