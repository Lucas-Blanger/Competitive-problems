#include <iostream>
using namespace std;

int main() {
    int N, L, D;
    cin >> N >> L >> D;

    int totalNecessario = N * D;      
    int capacidadePorVez = L * 1000;   

    int vezes = (totalNecessario + capacidadePorVez - 1) / capacidadePorVez;

    int totalPreparado = vezes * capacidadePorVez;


    cout << totalPreparado / 1000 << endl;

}