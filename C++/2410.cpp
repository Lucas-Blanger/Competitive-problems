#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;

    int pre = 0;

    map<int, bool> lista;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        if(!(lista.find(x) != lista.end())){
            lista[x] = true;
        }
    }

    for(auto x:lista){
        if(x.second == true) pre++;
    }

    cout << pre << endl;

}
    