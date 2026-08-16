#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<long long int, long long int> aux;

    long long int r = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(aux[x] > 0){
            r += aux[x];
            aux[x]++;
        }else aux[x]++;
        
    }


    cout << r<< endl;
}