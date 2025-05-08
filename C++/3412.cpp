#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();  
    cout << fixed << setprecision(1);

    for (int i = 0; i < n; ++i) {
        string nome;
        getline(cin, nome);

        string linhaNotas;
        getline(cin, linhaNotas);
        stringstream ss(linhaNotas);
        vector<double> notas;
        double nota;
        while (ss >> nota) {
            notas.push_back(nota);
        }

        double media = 0.0;

        if (notas.size() == 1) {
            media = (notas[0] + 0.0) / 2.0;
        } else if (notas.size() == 2) {
            media = (notas[0] + notas[1]) / 2.0;
        } else if (notas.size() == 3) {
            media = (notas[0] + notas[1] + notas[2]) / 3.0;
        } else if (notas.size() == 4) {
            double p1 = notas[0], p2 = notas[1], t1 = notas[2], ps = notas[3];
            double menor = min({p1, p2, t1});
            if (ps > menor) {
                if (menor == p1) p1 = ps;
                else if (menor == p2) p2 = ps;
                else t1 = ps;
            }
            media = (p1 + p2 + t1) / 3.0;
        }

        cout << nome << ": " << media << endl;
    }


}
