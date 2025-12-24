#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;  

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> f;
    long long x = 1;
    for (int i = 1; x <= N; i++) {
        f.push_back(x);
        x *= (i+1);
    }

    string n;

    while(true){
        cin >> n;
        if(n == "0") break;

        int r = 0;
        int cont = n.size();
        cont--;
        for(int i = 0; i < n.size(); i++){
            r += (n[i] - '0') * f[cont];
            cont--;

        }
        cout << r << endl;

    }





    
    
    
}