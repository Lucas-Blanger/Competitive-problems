#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,k;
    cin >> n;
    cin >> k;
    vector<int> m(n);

    for(int i = 0; i < n; i++){
        cin >> m[i];
    }

    sort(m.begin(), m.end(), greater<int>());
    int cont = 0;

    for(int i = 0; i < n; i++){
        if(i < k){
            cont++;
        }else if(i >= k && m[i] == m[k-1]){
            cont++;
        }
    }

    cout << cont << endl;

}