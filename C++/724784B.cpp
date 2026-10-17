#include <bits/stdc++.h>


using namespace std;


int main(){
    int n,b;
    cin >> n >> b;

    int r = b / n;
    if(b % n == 0)cout << r << endl;
    else cout << -1 << endl;
}