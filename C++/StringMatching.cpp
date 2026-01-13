#include <bits/stdc++.h>

using namespace std;

vector<int> computeLPS(string pat) {
    int m = pat.size();
    vector<int> lps(m);
    int len = 0;
    lps[0] = 0;
    
    for (int i = 1; i < m; ) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else {
            if (len != 0) len = lps[len - 1];
            else lps[i++] = 0;
        }
    }
    return lps;
}

long long int KMP(string txt, string pat) {
    vector<int> lps = computeLPS(pat);
    vector<int> result;
    int n = txt.size(), m = pat.size();
    int i = 0, j = 0;
    
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++; j++;
        }
        
        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && txt[i] != pat[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return result.size();
}

int main(){
    string principal, padrao;
    cin >> principal >> padrao;

    long long int aux = KMP(principal, padrao);

    cout << aux << endl;

    


}