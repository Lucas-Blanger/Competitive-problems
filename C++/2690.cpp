
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    unordered_map<char,int> mapa;
    mapa['G'] = 0;
    mapa['Q'] = 0;
    mapa['a'] = 0;
    mapa['k'] = 0;
    mapa['u'] = 0;

    mapa['I'] = 1;
    mapa['S'] = 1;
    mapa['b'] = 1;
    mapa['l'] = 1;
    mapa['v'] = 1;

    mapa['E'] = 2;
    mapa['O'] = 2;
    mapa['Y'] = 2;
    mapa['c'] = 2;
    mapa['m'] = 2;
    mapa['w'] = 2;

    mapa['F'] = 3;
    mapa['P'] = 3;
    mapa['Z'] = 3;
    mapa['d'] = 3;
    mapa['n'] = 3;
    mapa['x'] = 3;

    mapa['J'] = 4;
    mapa['T'] = 4;
    mapa['e'] = 4;
    mapa['o'] = 4;
    mapa['y'] = 4;

    mapa['D'] = 5;
    mapa['N'] = 5;
    mapa['X'] = 5;
    mapa['f'] = 5;
    mapa['p'] = 5;
    mapa['z'] = 5;

    mapa['A'] = 6;
    mapa['K'] = 6;
    mapa['U'] = 6;
    mapa['g'] = 6;
    mapa['q'] = 6;

    mapa['C'] = 7;
    mapa['M'] = 7;
    mapa['W'] = 7;
    mapa['h'] = 7;
    mapa['r'] = 7;

    mapa['B'] = 8;
    mapa['L'] = 8;
    mapa['V'] = 8;
    mapa['i'] = 8;
    mapa['s'] = 8;

    mapa['H'] = 9;
    mapa['R'] = 9;
    mapa['j'] = 9;
    mapa['t'] = 9;

    while(n--){
        string fra;
        getline(cin, fra);

        string num = "";
        for(int i = 0; i < fra.size(); i++){
            if(fra[i] != ' '){
                if (mapa.count(fra[i])) {
                    num += to_string(mapa[fra[i]]);
                }else continue;

                
                if (num.length() == 12) {
                    break;
                }
            }
        } 

        cout << num << '\n';
    }
    

}
