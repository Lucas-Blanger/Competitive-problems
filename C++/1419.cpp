#include <bits/stdc++.h>
using namespace std;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        int n;
        cin >> n;

        if(n==0) break;

        vector<int> pm(n);
        vector<int> pl(n);

        for(int i = 0; i < n; i++) cin >> pm[i];
        for(int i = 0; i < n; i++) cin >> pl[i];

        int pontosM = 0, pontosL = 0;

        bool bonus = false;
        int cM = 0, cL = 0;

        for(int i = 0; i < n; i++){
            if(i == 0){
                pontosM += pm[i];
                cM++;
                pontosL += pl[i];
                cL++;
            }else{
                pontosM += pm[i];
                if(pm[i] == pm[i-1])cM++;
                else cM = 1;
                
                pontosL += pl[i];
                if(pl[i] == pl[i-1])cL++;
                else cL = 1;

            }
            
            if(!bonus && cM >= 3 && cL >= 3) {
                bonus = true;
            }else if(!bonus && cM >= 3){
                pontosM += 30;
                bonus = true;
            }else if(!bonus && cL >= 3){
                pontosL += 30;
                bonus = true;
            }
        }


        if(pontosL > pontosM) cout << 'L' << endl;
        else if( pontosM > pontosL) cout << 'M' << endl;
        else cout << 'T' << endl;
    }
 
}