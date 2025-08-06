#include <bits/stdc++.h>

using namespace std;

int main() {
    string n;
    cin >> n;

    string contr = n;
    reverse(contr.begin(), contr.end());

    cout << n + contr << endl;

}