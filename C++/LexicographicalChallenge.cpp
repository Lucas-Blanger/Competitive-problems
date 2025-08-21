#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;

    int n = s.size();
    vector<vector<char>> grupos(k);

    for (int i = 0; i < n; i++)
        grupos[i % k].push_back(s[i]);

    for (int i = 0; i < k; i++)
        sort(grupos[i].begin(), grupos[i].end());

 
    vector<int> pos(k, 0);
    string res = s;
    for (int i = 0; i < n; i++) {
        res[i] = grupos[i % k][pos[i % k]];
        pos[i % k]++;
    }

    cout << res << endl;
}
