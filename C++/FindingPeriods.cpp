#include <bits/stdc++.h>


using namespace std;


const long long P1 = 31,  M1 = 1e9 + 7;
const long long P2 = 53,  M2 = 1e9 + 9;

struct DoubleHash {
    vector<long long> h1, h2, p1_pow, p2_pow;
    int n;
    
    DoubleHash(string s) {
        n = s.size();
        h1.resize(n + 1);
        h2.resize(n + 1);
        p1_pow.resize(n + 1);
        p2_pow.resize(n + 1);
        
        p1_pow[0] = p2_pow[0] = 1;
        for (int i = 1; i <= n; i++) {
            p1_pow[i] = (p1_pow[i-1] * P1) % M1;
            p2_pow[i] = (p2_pow[i-1] * P2) % M2;
        }
        
        h1[0] = h2[0] = 0;
        for (int i = 0; i < n; i++) {
            int val = s[i] - 'a' + 1;
            h1[i+1] = (h1[i] + val * p1_pow[i]) % M1;
            h2[i+1] = (h2[i] + val * p2_pow[i]) % M2;
        }
    }
    
    pair<long long, long long> getHash(int l, int r) {
        long long hash1 = (h1[r+1] - h1[l] + M1) % M1;
        long long hash2 = (h2[r+1] - h2[l] + M2) % M2;
        return {hash1, hash2};
    }
    
    bool compare(int l1, int r1, int l2, int r2) {
        auto [hash1_1, hash1_2] = getHash(l1, r1);
        auto [hash2_1, hash2_2] = getHash(l2, r2);
        
        // Normalizar potências
        if (l1 < l2) {
            hash1_1 = (hash1_1 * p1_pow[l2 - l1]) % M1;
            hash1_2 = (hash1_2 * p2_pow[l2 - l1]) % M2;
        } else if (l2 < l1) {
            hash2_1 = (hash2_1 * p1_pow[l1 - l2]) % M1;
            hash2_2 = (hash2_2 * p2_pow[l1 - l2]) % M2;
        }
        
        return hash1_1 == hash2_1 && hash1_2 == hash2_2;
    }
};


int main(){
    string s;
    cin >> s;

    DoubleHash dh(s);

    int n = s.size();

    for (int i = 1; i <= n; i++) {
        if (i == n) {
            // String completa é sempre período
            cout << i << " ";
        } else {
            // Comparar prefixo com sufixo deslocado
            if (dh.compare(0, n-i-1, i, n-1)) {
                cout << i << " ";
            }
        }
    }


}