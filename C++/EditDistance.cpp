#include <bits/stdc++.h>



using namespace std;

int editDistance(string a, string b) {
    int n = a.size();
    int m = b.size();

    vector<int> prev(m + 1), cur(m + 1);

    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++) {

        cur[0] = i;

        for (int j = 1; j <= m; j++) {

            if (a[i-1] == b[j-1])
                cur[j] = prev[j-1];
            else
                cur[j] = 1 + min({
                    prev[j],     // remover
                    cur[j-1],    // inserir
                    prev[j-1]    // substituir
                });
        }

        prev = cur;
    }

    return prev[m];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a,b;
    cin >> a >> b;
    cout << editDistance(a,b) << endl;

   
}