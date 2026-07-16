#include <bits/stdc++.h>


using namespace std;

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;
    vector<int> aux(n,0);

    
    int r = 0;
    if(n == 1 && s[0] == 'a') r++;
    if(n > 1 && s[0] == 'a' && s[1] == 'a') r++;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1] && s[i] == 'a'){
            r++;
        }else{
            if(i != n-1) if(s[i] == 'a' && s[i+1] == 'a') r++;
            aux[i] = 1;
        }
    }


    cout << r << endl;
    
}