#include <bits/stdc++.h>
#define MAXN (int)(1e6 + 10)

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,c;
    cin >> n >> c;

    unordered_map<string,int> mapa;

    for(int i = 0; i <n;i++){
        string p;
        cin >> p;
        size_t pos = p.find('*');

        for(char j = 'a'; j <= 'z'; ++j){
            p[pos] = j;
            mapa[p]++;
        }
    }

    string r = "";
    int fre = 0;

    for(auto&p : mapa){
        if(p.second > fre){
            fre = p.second;
            r = p.first;
        }else if(p.second == fre){
            if(p.first < r) r = p.first;
        }
    }

    cout << r << " " << fre << endl;

}