#include <bits/stdc++.h>

using namespace std;




int main() {
    map<char, int> alfa;

    alfa['a'] = 0;
    alfa['b'] = 0;
    alfa['c'] = 0;
    alfa['d'] = 0;
    alfa['e'] = 0;
    alfa['f'] = 0;
    alfa['g'] = 0;
    alfa['h'] = 0;
    alfa['i'] = 0;
    alfa['j'] = 0;
    alfa['k'] = 0;
    alfa['l'] = 0;
    alfa['m'] = 0;
    alfa['n'] = 0;
    alfa['o'] = 0;
    alfa['p'] = 0;
    alfa['q'] = 0;
    alfa['r'] = 0;
    alfa['s'] = 0;
    alfa['t'] = 0;
    alfa['u'] = 0;
    alfa['v'] = 0;
    alfa['w'] = 0;
    alfa['x'] = 0;
    alfa['y'] = 0;
    alfa['z'] = 0;

    int n;
    cin >> n;
    string s;
    cin >> s;

    bool pass = true;
    for(int i = 0; i < s.size(); i++){
        s[i] = tolower(s[i]);
        alfa[s[i]]++;
    }

    for(auto x:alfa){
        if(x.second == 0) pass = false;
    }

    if(pass) cout << "YES" << endl;
    else cout << "NO" << endl;

}
