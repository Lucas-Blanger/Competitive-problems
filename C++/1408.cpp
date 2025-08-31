#include <bits/stdc++.h>
using namespace std;

int n, l;
int Num_armarios[100000];

int verifica(int inicio) {
    int i = inicio;
    int posFinal = Num_armarios[inicio] + n;

    while (true) {
        if (i < l && Num_armarios[i] < posFinal) {
            i++;
        } else {
            break;
        }
    }

    return i - inicio;
}

int melhorSeq() {
    int MaiorSeqPossivel = 0;
    int indFinal = l - 1;

    while (indFinal > 0 && Num_armarios[indFinal] > Num_armarios[l - 1] - n) {
        indFinal--;
    }

    if (indFinal < l - 1 && Num_armarios[indFinal] < Num_armarios[l - 1] - n) {
        indFinal++;
    }

    for (int i = 0; i <= indFinal; i++) {
        int x = verifica(i);
        if (x > MaiorSeqPossivel) {
            MaiorSeqPossivel = x;
        }
    }

    return MaiorSeqPossivel;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> n >> l;
        if (n == 0) break;

        for (int i = 0; i < l; i++) {
            cin >> Num_armarios[i];
        }

        cout << (n - melhorSeq()) << "\n";
    }

    return 0;
}
