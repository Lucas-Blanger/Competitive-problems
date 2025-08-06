#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int p = 0;
    for(int i = 0; i < n ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if((a == b && a != 0 ) || (b == c && b != 0) || (a == c && c != 0)){
            p++;
        }
    }
    cout << p << endl;
}