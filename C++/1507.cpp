#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string r) {
    int j = 0; 
    
    for (int i = 0; i < s.size() && j < r.size(); i++) {
        if (s[i] == r[j]) {
            j++;
        }
    }
    
    return j == r.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    while(n--){
        string s;
        cin >> s;
        
        int q;
        cin >> q;
        
        while(q--){
            string r;
            cin >> r;
            
            if(isSubsequence(s, r))cout << "Yes" << endl;
            else cout << "No" << endl;
            
        }
    }
    
}