#include <bits/stdc++.h>
using namespace std;

int lPos[9];
bool linhaUsada[9];
bool diag1[20];
bool diag2[20];

int cont;
int lFixa, cFixa;

void backtrack(int col) {

    if (col == 9) {
        cont++;
        cout << setw(2) << cont << "      ";
        for (int i = 1; i <= 8; i++) {
            cout << lPos[i];
            if (i != 8) cout << " ";
        }
        cout << endl;
        return;
    }

    for (int r = 1; r <= 8; r++) {

        if (col == cFixa && r != lFixa)
            continue;

        if (!linhaUsada[r] &&
            !diag1[r + col] &&
            !diag2[r - col + 8]) {

            lPos[col] = r;
            linhaUsada[r] = true;
            diag1[r + col] = true;
            diag2[r - col + 8] = true;

            backtrack(col + 1);

            linhaUsada[r] = false;
            diag1[r + col] = false;
            diag2[r - col + 8] = false;
        }
    }
}

int main() {

    int t;
    cin >> t;

    while (t--) {

        cin >> lFixa >> cFixa;

        cont = 0;

        memset(linhaUsada, false, sizeof(linhaUsada));
        memset(diag1, false, sizeof(diag1));
        memset(diag2, false, sizeof(diag2));

        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";

        backtrack(1);

        if (t) cout << endl;
    }

}
