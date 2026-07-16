#include <bits/stdc++.h>

using namespace std;


int main(){
    bool r =true;
    for(int i = 0; i < 8;i++){
        int x;
        cin >> x;
        if(x != 0 && x != 1) r = false;
    }

    if(r) cout << 'S' << endl;
    else cout << 'F' << endl;

}