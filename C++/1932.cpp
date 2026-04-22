#include <bits/stdc++.h>


using namespace std;

int main(){
    int n,c;
    cin >> n >> c;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long L = 0;
    int minPreco = a[0];

    for(int i = 1; i < n; i++){
        if(a[i] < minPreco){
            minPreco = a[i];
        }
        else if(a[i] > minPreco + c){
            L += a[i] - minPreco - c;
            minPreco = a[i] - c;
        }
    }

    cout << L << endl;
    
}