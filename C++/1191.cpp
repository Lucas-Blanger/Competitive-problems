#include <bits/stdc++.h>


using namespace std;

string pre, in;

void solve(string pre, string in) {

    if (pre.empty())
        return;

    char raiz = pre[0];

    int pos = in.find(raiz);

    // esquerda
    string inEsq = in.substr(0, pos);
    string preEsq = pre.substr(1, inEsq.size());

    // direita
    string inDir = in.substr(pos + 1);
    string preDir = pre.substr(1 + inEsq.size());

    solve(preEsq, inEsq);
    solve(preDir, inDir);

    cout << raiz;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> pre >> in) {

        solve(pre, in);
        cout << '\n';
    }

}