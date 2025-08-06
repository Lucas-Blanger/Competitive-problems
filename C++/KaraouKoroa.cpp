#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    vector<pair<int, int>> resultados;

    for (int c = a; c <= x; c++) {
        for (int d = b; d <= y; d++) {
            if (c > d) {
                resultados.push_back({c, d});
            }
        }
    }

    sort(resultados.begin(), resultados.end());

    cout << resultados.size() << endl;
    for (auto par : resultados) {
        cout << par.first << " " << par.second << endl;
    }

}
