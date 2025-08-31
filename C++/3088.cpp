#include <bits/stdc++.h>
using namespace std;

int main() {
    string linha;

    while (getline(cin, linha)) {
        for (size_t i = 0; i < linha.size(); i++) {
            if (linha[i] == ' ') {
                if (i + 1 < linha.size() && (linha[i + 1] == ',' || linha[i + 1] == '.')) {
                    cout << linha[i + 1];
                    i++; 
                } else {
                    cout << linha[i];
                }
            } else {
                cout << linha[i];
            }
        }
        cout << '\n';
    }


}
