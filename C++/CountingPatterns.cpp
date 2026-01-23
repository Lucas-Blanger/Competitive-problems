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
};

long long rabinKarp(DoubleHash& textHash, string pattern) {
    int n = textHash.n;
    int m = pattern.size();
    
    if (m > n) return 0;
    
    DoubleHash patternHash(pattern); 
    
    auto pHash = patternHash.getHash(0, m - 1);
    long long count = 0;
    
    for (int i = 0; i <= n - m; i++) {
        auto tHash = textHash.getHash(i, i + m - 1); 
        
        auto [pHash1, pHash2] = pHash;
        auto [tHash1, tHash2] = tHash;
        
        long long normalizedP1 = (pHash1 * textHash.p1_pow[i]) % M1;
        long long normalizedP2 = (pHash2 * textHash.p2_pow[i]) % M2;
        
        if (tHash1 == normalizedP1 && tHash2 == normalizedP2) {
            count++;
        }
    }
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    int q;
    cin >> s >> q;
    
    DoubleHash textHash(s);
    
    while(q--) {
        string pat;
        cin >> pat;
        
        long long result = rabinKarp(textHash, pat);
        cout << result << "\n";
    }
    
}