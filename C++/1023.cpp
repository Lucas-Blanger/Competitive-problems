#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, consumo, cidade = 1;

    while (true) {
        cin >> n;
        if (n == 0) break;

        vector<int> Resident(210, 0);
        int somap = 0, somaConsumo = 0;

        for (int i = 0; i < n; i++) {
            cin >> p >> consumo;
            somap += p;
            somaConsumo += consumo;

            Resident[consumo / p] += p;
        }

        cout << "Cidade# " << cidade << ":\n";
        cidade++;

        bool primeiro = true;
        for (int i = 0; i < 210; i++) {
            if (Resident[i] > 0) {
                if (!primeiro) cout << " ";
                primeiro = false;
                cout << Resident[i] << "-" << i;
            }
        }
        cout << endl;

        int total1 = (double)somaConsumo / (double)somap * 100;
        int total2 = (double)somaConsumo / (double)somap;
        total2 = total2 * 100;
        int diff = total1 - total2;
        total1 = total1 / 100;

        cout << "Consumo medio: " << total1 << "." 
             << setfill('0') << setw(2) << diff << " m3.\n";

        cout << endl;
    }


}
