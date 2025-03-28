#include <iostream>

using namespace std;

int main() {
    int hi, mi, hf, mf;
    cin >> hi >> mi >> hf >> mf;

    int totalHoras, totalMinutos;

    int inicio = hi * 60 + mi;
    int fim = hf * 60 + mf;

    if (inicio >= fim) {
        fim += 24 * 60; 
    } 

    int duracao = fim - inicio;
    totalHoras = duracao / 60;
    totalMinutos = duracao % 60;

    cout << "O JOGO DUROU " << totalHoras << " HORA(S) E " << totalMinutos << " MINUTO(S)" << endl;


}


