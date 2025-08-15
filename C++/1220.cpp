#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0) {
        vector<long long> gastos(n);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            double aux;
            cin >> aux;
            gastos[i] = llround(aux * 100.0); 
            total += gastos[i];
        }

        long long media = total / n;
        int resto = total % n;
        long long totalTrocar = 0;

        for (int i = 0; i < n; i++) {
            if (gastos[i] > media) {
                if (resto > 0) {
                    totalTrocar += gastos[i] - media - 1;
                    resto--;
                } else {
                    totalTrocar += gastos[i] - media;
                }
            }
        }

        cout << "$" << (totalTrocar / 100) << "."
             << setw(2) << setfill('0') << (totalTrocar % 100) << "\n";
    }

}
