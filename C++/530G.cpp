#include <bits/stdc++.h>



using namespace std;


map<char, int> alphabet;



void complete(){
    for(int i = 0; i < 26; i++){
        alphabet['a' + i] = i + 1; 
    }

}

void editDistance(string a, string b) {
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else {
                int rem = dp[i-1][j] + alphabet[a[i-1]];
                int ins = dp[i][j-1] + alphabet[b[j-1]];
                int sub = dp[i-1][j-1] + abs(alphabet[a[i-1]] - alphabet[b[j-1]]);

                dp[i][j] = min({rem, ins, sub});
            }
        }
    }

    cout << dp[n][m] << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a,b;
    cin >> a >> b;
    complete();
    editDistance(a,b);

   
}