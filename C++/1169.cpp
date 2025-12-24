#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    while(n--){
        int x;
        cin >> x;
        
        unsigned long long kg;
        
        if(x < 5) {
            kg = (1ULL << x) / 12000;
        } else {
            kg = (1ULL << (x - 5)) / 375;
        }
        
        cout << kg << " kg" << endl;
    }
    
}