#include <bits/stdc++.h>



using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long int S = 0;
    vector<long long int> aux(n);
    for(int i = 0; i < n;i++){
        cin >> aux[i];
        S += aux[i];
    }

    vector<bool> dp(S + 1, false);
    dp[0] = true;

    for (long long int x : aux) {
        for (long long int s = S; s >= x; s--) {
            dp[s] = dp[s] || dp[s - x];
        }
    }
    
    vector<int> res;
    for(int s = 1; s <= S; s++)
        if(dp[s]) res.push_back(s);

    cout << res.size() << "\n";
    for(int i = 0; i < (int)res.size(); i++){
        if(i) cout << " ";
        cout << res[i];
    }
    cout << "\n";

   
}