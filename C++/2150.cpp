#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string vogais, frase;
    while (true) {
        if (!getline(cin, vogais)) break;
        if (!getline(cin, frase)) break;

        unordered_set<char> st(vogais.begin(), vogais.end());
        int cnt = 0;
        for (char c : frase) {
            if (st.count(c)) cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
