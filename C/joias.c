#include <stdio.h>

void rotacionar90Graus(int n, int matriz[n][n], int resultado[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = matriz[j][n - 1 - i];
        }
    }
}

int estaOrdenada(int n, int matriz[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (matriz[i][j] <= matriz[i][j - 1]) {
                return 0;
            }
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 1; i < n; i++) {
            if (matriz[i][j] <= matriz[i - 1][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int matriz[n][n];
    int rotacionada[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int r = 0; r < 4; r++) {
        if (estaOrdenada(n, matriz)) {
            printf("%d\n", r);
            break;
        }
        rotacionar90Graus(n, matriz, rotacionada);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matriz[i][j] = rotacionada[i][j];
            }
        }
    }

}
