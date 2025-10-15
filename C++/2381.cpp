#include <bits/stdc++.h>

using namespace std;


int main(){
   int n, k;
   cin >> n >> k;
    vector<pair<string, int>> r;

    for(int i = 0; i < n; i++){
        string nome;
        cin >> nome;
        r.push_back(make_pair(nome, 0));
    }

    stable_sort(r.begin(), r.end(), [](const pair<string,int> &a, const pair<string,int> &b){
        return a.first < b.first;
    });


    for(int i = 0; i < n; i++){
        r[i].second = i+1;
        if (r[i].second == k) cout << r[i].first << endl;
    
    }


}