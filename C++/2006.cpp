#include <bits/stdc++.h>


using namespace std;

int main(){

    int t;
    cin >> t;
    int r = 0;
    
    
    for(int i = 0; i < 5; i++){
        int x;
        cin >> x;
        if(x == t) r++;
    }
    cout << r << endl;
}