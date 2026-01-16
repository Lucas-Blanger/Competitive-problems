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


    int t = borders.size();
    int p = borders[t-1]; 

    set<int> aux;
    for(int i = 0; i < t-1; i++) {
        if(borders[i] > 0) aux.insert(borders[i]);
    }

    while(p > 0) {
        if(aux.count(p)) {  
            cout << s.substr(0,p) << endl;
            return 0;
        }
        p = borders[p-1];  
    }

    cout << "Just a legend" << endl;
    
}