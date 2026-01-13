#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string s) {
    int n = s.size();
    vector<int> lps(n);
    int len = 0;
    lps[0] = 0;
    
    for (int i = 1; i < n; ) {
        if (s[i] == s[len]) {
            lps[i++] = ++len;
        } else {
            if (len != 0) len = lps[len - 1];
            else lps[i++] = 0;
        }
    }
    return lps;
}

int main() {
    string s;
    cin >> s;
    
    vector<int> lps = computeLPS(s);
    vector<int> borders;
    
    int idx = lps[s.size() - 1];
    
    while (idx > 0) {
        borders.push_back(idx);
        idx = lps[idx - 1];
    }
    
   
    reverse(borders.begin(), borders.end());
    
    for (int b : borders) {
        cout << b << " ";
    }
    if (!borders.empty()) cout << "\n";
    

}