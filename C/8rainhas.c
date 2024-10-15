#include <stdio.h>
#include <stdbool.h>


#define tm 8
char tabuleiro[tm][tm];  




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


	for (int c = 0; c < coluna; c++) {
    	if (tabuleiro[linha][c] == 'R') {
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




bool colocaRainha(int linha) {
	if (linha >= tm) {
    	return true;  
	}


	for (int coluna = 0; coluna < tm; coluna++) {
    	if (verifica(linha, coluna)) {
        	tabuleiro[linha][coluna] = 'R';  
        	if (colocaRainha(linha + 1)) {   
            	return true;
        	}
        	tabuleiro[linha][coluna] = '.';  
    	}
	}


	return false;  
}


void exibeTabuleiro() {
	for (int i = 0; i < tm; i++) {
    	for (int j = 0; j < tm; j++) {
        	printf("%c ", tabuleiro[i][j]);
    	}
    	printf("\n");
	}
}


int main() {
	inicializaTabuleiro();
	if (colocaRainha(0) == true) {
    	exibeTabuleiro();
	}
}
