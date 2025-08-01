#include <iostream>
#include <cstdio>
#define INF 999999999
#define MAX_V 501

using namespace std;

int grafo[MAX_V][MAX_V], num_cidades;

int dijkstra(int inicio, int fim) {
    int custo[MAX_V], visitado[MAX_V];
    for (int i = 1; i <= num_cidades; i++) {
        custo[i] = INF;
        visitado[i] = 0;
    }

    custo[inicio] = 0;
    int atual = inicio;

    while (atual != fim) {
        for (int i = 1; i <= num_cidades; i++) {
            if (custo[i] > custo[atual] + grafo[atual][i]) {
                custo[i] = custo[atual] + grafo[atual][i];
            }
        }

        visitado[atual] = 1;

        int menor = INF;
        for (int i = 1; i <= num_cidades; i++) {
            if (!visitado[i] && custo[i] < menor) {
                menor = custo[i];
                atual = i;
            }
        }

        if (menor == INF) return INF;
    }

    return custo[fim];
}

int main() {
    int num_estradas;

    cin >> num_cidades >> num_estradas;

    while (num_cidades != 0 || num_estradas != 0) {

        for (int i = 1; i <= num_cidades; i++) {
            for (int j = 1; j <= num_cidades; j++) {
                grafo[i][j] = INF;
            }
        }

        for (int i = 0; i < num_estradas; i++) {
            int u, v, tempo;
            cin >> u >> v >> tempo;

            grafo[u][v] = tempo;

            if (grafo[v][u] != INF) {
                grafo[u][v] = 0;
                grafo[v][u] = 0;
            }
        }

        int num_consultas;
        cin >> num_consultas;

        for (int i = 0; i < num_consultas; i++) {
            int origem, destino;
            cin >> origem >> destino;

            int resposta = dijkstra(origem, destino);

            if (resposta == INF) {
                cout << "Nao e possivel entregar a carta\n";
            } else {
                cout << resposta << endl;
            }
        }

        cin >> num_cidades >> num_estradas;
        cout << endl;
    }


}
