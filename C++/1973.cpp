#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> carneiros(N);
    for (int i = 0; i < N; ++i)
        cin >> carneiros[i];

    vector<bool> visitada(N, false);
    int i = 0;
    while (i >= 0 && i < N) {
        if (carneiros[i] > 0) {
            carneiros[i]--;         
            visitada[i] = true;     
            if ((carneiros[i] + 1) % 2 == 1)
                i++;                
            else
                i--;               
        } else {
            visitada[i] = true;     
            break;
        }
    }

    int estrelasAtacadas = 0;
    long long carneirosRestantes = 0;

    for (int j = 0; j < N; ++j) {
        if (visitada[j]) estrelasAtacadas++;
        carneirosRestantes += carneiros[j];
    }

    cout << estrelasAtacadas << " " << carneirosRestantes << endl;

    return 0;
}
