#include <bits/stdc++.h>
#define MAXN (int)(2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define MOD (int)(1e9 + 7)

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<long long int> f;
    long long x = 1;
    for (int i = 1; x <= n; i++) {
        f.push_back(x);
        x *= (i+1);
    }

    int r = 0;
    vector<long long int> a;
    for(int i = f.size() - 1; i >= 0; i--){
        while(n >= f[i]){
            n -= f[i];
            r++;
        }
    }

    cout << r << endl;





    
  





}

