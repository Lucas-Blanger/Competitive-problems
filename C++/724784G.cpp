#include <bits/stdc++.h>


using namespace std;


int main(){
    char c;
    cin >> c;

    string p;
    cin >> p;

    int r = -1;

    for(int i = 0; i < p.size(); i++){
        if(p[i] == c){
            cout << i + 1 << endl;
            r = i+1;
            break;
        }
    }

    if(r == -1) cout << r << endl;

}