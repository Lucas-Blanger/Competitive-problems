#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Aresta {
    int u, v;
};


struct Grafo {
    int V, A;
    struct Aresta* arestas;
};

int encontrar(int parent[], int i) {
    if (parent[i] == i) {
        return i;
    }
    return encontrar(parent, parent[i]);
}

void unir(int parent[], int rank[], int x, int y) {
    int raiz_x = encontrar(parent, x);
    int raiz_y = encontrar(parent, y);

    if (rank[raiz_x] < rank[raiz_y]) {
        parent[raiz_x] = raiz_y;
    } else if (rank[raiz_x] > rank[raiz_y]) {
        parent[raiz_y] = raiz_x;
    } else {
        parent[raiz_y] = raiz_x;
        rank[raiz_x]++;
    }
}

int kruskal(struct Grafo* grafo) {
    int V = grafo->V;
    int A = grafo->A;
    struct Aresta* arestas = grafo->arestas;
    
    int parent[MAX], rank[MAX];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int peso_total = 0;
    int arestas_incluidas = 0;
    
    for (int i = 0; i < A; i++) {
        int u = arestas[i].u;
        int v = arestas[i].v;

        int raiz_u = encontrar(parent, u);
        int raiz_v = encontrar(parent, v);

        if (raiz_u != raiz_v) {
            unir(parent, rank, raiz_u, raiz_v);
            peso_total++;
            arestas_incluidas++;
        }
    }

    return peso_total;
}

int main() {
    int T;  
    scanf("%d", &T);
    
    while (T--) {
        int inicio;  
        scanf("%d", &inicio);

        int V, A;
        scanf("%d %d", &V, &A);

        struct Grafo grafo;
        grafo.V = V;
        grafo.A = A;
        grafo.arestas = (struct Aresta*)malloc(A * sizeof(struct Aresta));

        for (int i = 0; i < A; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            grafo.arestas[i].u = u;
            grafo.arestas[i].v = v;
        }

        int movimentos = 2 * kruskal(&grafo);
        printf("%d\n", movimentos);

        free(grafo.arestas);
    }

    return 0;
}
