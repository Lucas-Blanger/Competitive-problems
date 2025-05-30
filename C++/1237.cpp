#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    
    while (getline(cin, s1) && getline(cin, s2)) {
        int m = s1.size();
        int n = s2.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maior = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maior = max(maior, dp[i][j]);
                }
             
            }
        }

        cout << maior << endl;
    }

}
