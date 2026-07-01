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

    int n, m;
    cin >> n >> m;
    
    int total = 8 * n;

    cout << total/m << endl;
}
