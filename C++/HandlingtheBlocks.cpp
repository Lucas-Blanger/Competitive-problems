#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> pares;
    vector<pair<int, int>> aux;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        pares.push_back(make_pair(a, b));
        aux.push_back(make_pair(a, b));
    }
    sort(pares.begin(), pares.end());
    bool passou = true;

    for(int i = 0; i < n; i++){
        if(k == 1){
            break;
        }
        if(pares[i].second != aux[i].second){
            passou = false;
        }
    }

    if (passou){
        cout << "Y" << endl;
    }else{
        cout << "N" << endl;
    }



}