#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int terreno[1000][1000];


    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> terreno[i][j];


    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            if (terreno[i][j] == 42 &&
                terreno[i-1][j-1] == 7 &&
                terreno[i-1][j]   == 7 &&
                terreno[i-1][j+1] == 7 &&
                terreno[i][j-1]   == 7 &&
                terreno[i][j+1]   == 7 &&
                terreno[i+1][j-1] == 7 &&
                terreno[i+1][j]   == 7 &&
                terreno[i+1][j+1] == 7) {

                cout << i+1 << " " << j+1 << endl;
                return 0;
            }
        }
    }


    cout << "0 0" << endl;

}
