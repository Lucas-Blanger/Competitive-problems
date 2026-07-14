#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    double l,q;
    cin >> n >> l >> q;

    map<int, string> p;

    for(int i = 0; i < n; i++){
        string nome;
        cin >> nome;

        p[i] = nome; 
    }

    cout << fixed << setprecision(1);
    int first = 0;
    while(l != 0){
        if(l-q <= 0){
            cout << p[first] << " " << l << endl;
            break;
        }else{
            l -= q;
            if(first +1 == n) first = 0;
            else first++;
        }
    }


}