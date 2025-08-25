#include <bits/stdc++.h>

using namespace std;

const int MAX_M = 1000;

int main() {
    int n, m;
    cin >> n >> m;
    
    bitset<MAX_M+1> s0; 
    int l;
    cin >> l;
    for (int i = 0; i < l; i++) {
        int lamp;
        cin >> lamp;
        s0.set(lamp);
    }
    
    vector<bitset<MAX_M+1>> switches(n+1); 
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int lamp;
            cin >> lamp;
            switches[i].set(lamp);
        }
    }
    
    bitset<MAX_M+1> T;
    for (int i = 1; i <= n; i++) {
        T ^= switches[i];
    }
    
    vector<bitset<MAX_M+1>> S(n+1);
    S[0].reset();
    for (int i = 1; i <= n; i++) {
        S[i] = S[i-1] ^ switches[i];
    }
    
    int best = INT_MAX;

    for (int j = 0; j < n; j++) {
        bitset<MAX_M+1> b = s0 ^ S[j];
        if (T.none()) { 
            if (b.none()) {
                best = min(best, j);
            }
        } else {
            if (b.none()) {
                best = min(best, j); 
            } else if (b == T) {
                best = min(best, n + j); 
            }
        }
    }
    
    if (best != INT_MAX) {
        cout << best << endl;
    } else {
        cout << -1 << endl;
    }
    
}