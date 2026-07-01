#include <bits/stdc++.h>
#define MAXN (int)(2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define MOD (int)(1e9 + 7)
const int N = 1e6;     
long long fat[N+1];
long long invfat[N+1];
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    
    vector<int> t(n);
 
    int cont = 0;
    bool first = true;
    bool second = true;
    for(int i = 0; i < n;i++){
        cin >> t[i];
        if(cont + t[i] > 120 && first){
            cont += 180 + t[i];
            first = false;
            continue;
        }
        if(cont + t[i] > 720 && second){
            cont += 180 + t[i];
            second = false;
            continue;
        }
        cont += t[i];
 
    }
    cout << cont << endl;
}