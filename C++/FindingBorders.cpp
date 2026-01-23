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

int main() {
    string s;
    cin >> s;

    vector<int> borders = computeLPS(s);

    int t = s.size();
    int k = borders[t - 1];

    vector<int> aux;
    while (k > 0) {
        aux.push_back(k);
        k = borders[k-1]; // vai para a próxima borda
    }

    sort(aux.begin(), aux.end());

    for(int x: aux){
        cout << x << " ";
    }
    
    

}