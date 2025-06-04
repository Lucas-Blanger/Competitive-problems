#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, caso = 1;
    while (cin >> N) {
        vector<int> sequencia;
        for (int i = 0; i <= N; ++i)
            for (int j = 0; j < i; ++j)
                sequencia.push_back(i);
        sequencia.insert(sequencia.begin(), 0);
        int tamanho = sequencia.size();
        cout << "Caso " << caso++ << ": " << tamanho << (tamanho == 1 ? " numero\n" : " numeros\n");
        for (int i = 0; i < tamanho; ++i) {
            if (i > 0) cout << " ";
            cout << sequencia[i];
        }
        cout << "\n\n";
    }
    return 0;
}
