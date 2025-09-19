#include <bits/stdc++.h>

using namespace std;

int main(){
    int d, n;

    while(cin >> d >> n){
        int money = 0, distl = d;

        vector<tuple<char, int, int>> c;
        for(int i = 0; i < n; i++){
            char a;
            int p, t = 0;
            cin >> a;
            if(a == 'C'){
                cin >> p >> t;
                c.push_back(make_tuple(a, p, t));
            }else{
                cin >> p;
                c.push_back(make_tuple(a, p, t));
                for(int j = 0; j < c.size(); j++ ){
                    if(get<1>(c[j]) == get<1>(c[i])){
                        get<2>(c[i]) = get<2>(c[j]);
                    }
                }
            }
        }

        for(int i = 0; i < c.size(); i++){
            if(get<2>(c[i]) <= distl && get<0>(c[i]) == 'C'){
                money += 10;
                distl -= get<2>(c[i]);
            }
            if(get<0>(c[i]) == 'S'){
                distl += get<2>(c[i]); 
            }
          
        }

        cout << money << endl;
    }
}