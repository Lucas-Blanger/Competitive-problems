#include <stdio.h>
#include <stdbool.h>

#define tm 8
char tabuleiro[tm][tm];
int contador = 0; 

void inicializaTabuleiro() {
    for (int i = 0; i < tm; i++) {
        for (int j = 0; j < tm; j++) {
            tabuleiro[i][j] = '.';
        }
    }
}

bool verifica(int linha, int coluna) {
    for (int l = 0; l < linha; l++) {
        if (tabuleiro[l][coluna] == 'R') {
            return false;
        }
    }

    for (int i = 0; i < linha; i++) {
        int j = coluna - (linha - i);
        if (j >= 0 && tabuleiro[i][j] == 'R') {
            return false;
        }
    }

    for (int i = 0; i < linha; i++) {
        int j = coluna + (linha - i);
        if (j < tm && tabuleiro[i][j] == 'R') {
            return false;
        }
    }
    return true;
}

void exibeTabuleiro() {
    printf("Solucao %d:\n", ++contador);
    for (int i = 0; i < tm; i++) {
        for (int j = 0; j < tm; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void colocaRainha(int linha) {
    if (linha >= tm) {
        exibeTabuleiro(); 
        return;
    }

    for (int coluna = 0; coluna < tm; coluna++) {
        if (verifica(linha, coluna) == true) {
            tabuleiro[linha][coluna] = 'R';
            colocaRainha(linha + 1);
            tabuleiro[linha][coluna] = '.'; 
        }
    }
}

int main() {
    inicializaTabuleiro();
    colocaRainha(0);
    printf("Numero total de solucoes: %d\n", contador);
}
