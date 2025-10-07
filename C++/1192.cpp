#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        char dig;
        cin >> s;
        int d1, d2;

        d1 = s[0] - '0';
        d2 = s[2] - '0';
        dig = s[1];

        if(d1 == d2){
            cout << d1 * d2 << endl;
            continue;
        }

        if((int)dig < 96){
            cout << d2 - d1 << endl;
            continue;
        }else{
            cout << d1 + d2 << endl;
            continue;
        }



        
    }


}