#include <bits/stdc++.h>

using namespace std;

int c[101][101];
int b[101][101];
string X, Y;

int LCSlength() {
    int m = X.size(), n = Y.size();
    for (int i = 0; i <= m; i++) c[i][0] = 0;
    for (int j = 0; j <= n; j++) c[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1; // diagonal
            } else if (c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = 2; // de cima
            } else {
                c[i][j] = c[i][j-1];
                b[i][j] = 3; // da esquerda
            }
        }
    }
    return c[m][n];
}


int main() {

    while(getline(cin,X) && getline(cin,Y)){

        int r = 0;

        int t1 = X.size();
        int t2 = Y.size();
        cout << "Tamanho da LCS: " << LCSlength() << "\n";



       
    }
}
