#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> par;
    vector<int> impar;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x % 2==0){
            par.push_back(x);
        }else{
            impar.push_back(x);
        }
    }

    sort(par.begin(), par.end());
    sort(impar.begin(), impar.end());
    reverse(impar.begin(), impar.end());

    for(int i = 0; i < par.size(); i++){
        cout << par[i] << endl;
    }

    for(int i = 0; i < impar.size(); i++){
        cout << impar[i] << endl;
    }

}