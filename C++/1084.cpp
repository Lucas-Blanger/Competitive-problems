#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    while (cin >> n >> d && (n || d)) {
        string num;
        cin >> num;

        string pilha = "";
        int aux = d;

        for (char c : num) {
            while (aux > 0 && !pilha.empty() && pilha.back() < c) {
                pilha.pop_back();
                aux--;
            }
            pilha += c;
        }

        pilha = pilha.substr(0, pilha.size() - aux);

        cout << pilha << "\n";
    }

}