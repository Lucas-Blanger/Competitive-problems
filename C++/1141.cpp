#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_MAX_STR 1129
#define TAM_MAX 1000009
#define TAM_MAX_M 10009

int contador_nos = 1;

int indice_palavra[TAM_MAX]; // x
int dp[TAM_MAX_M];           // y
int link_falho[TAM_MAX];     // l
int fila[TAM_MAX << 2];      // f
int trie[TAM_MAX][26];

typedef struct _string {
    char texto[TAM_MAX_STR];
} string_t;

string_t palavras[TAM_MAX_M];

int construir_automato();
int resolver(char *);
void inserir(int, char *);
int comparar(const void *, const void *);

int maximo(int a, int b);

int main(int argc, char **argv) {
    int n;
    int resposta;

    while (scanf("%d", &n), n) {
        contador_nos = 1;

        for (size_t i = 0; i < n; ++i)
            scanf("%s", palavras[i].texto), dp[i + 1] = 0;

        qsort(palavras, n, sizeof(string_t), comparar);

        for (size_t i = 0; i < n; ++i)
            inserir(i + 1, palavras[i].texto);

        construir_automato();

        resposta = 1;
        dp[1] = 1;

        for (size_t i = 1; i < n; ++i)
            resposta = maximo(resposta, dp[i + 1] = resolver(palavras[i].texto));

        printf("%d\n", resposta);

  
        for (size_t i = 0; i < contador_nos; ++i) {
            indice_palavra[i] = link_falho[i] = 0;
            for (size_t j = 0; j < 26; ++j)
                trie[i][j] = 0;
        }
    }

    return 0;
}


int comparar(const void *a, const void *b) {
    return strlen(((string_t *)a)->texto) > strlen(((string_t *)b)->texto);
}


void inserir(int idx, char *s) {
    int atual = 0;
    size_t tamanho = strlen(s);

    for (size_t i = 0; i < tamanho; ++i) {
        int letra = s[i] - 'a';
        if (!trie[atual][letra])
            trie[atual][letra] = contador_nos++;

        atual = trie[atual][letra];
    }

    indice_palavra[atual] = idx;
}


int construir_automato() {
    int inicio, fim;
    inicio = fim = 0;

    fila[fim++] = 0;

    while (inicio < fim) {
        int atual = fila[inicio++];
        indice_palavra[atual] = maximo(indice_palavra[atual], indice_palavra[link_falho[atual]]);

        for (size_t i = 0; i < 26; ++i) {
            if (trie[atual][i]) {
                int filho = trie[atual][i];
                fila[fim++] = filho;
                link_falho[filho] = atual ? trie[link_falho[atual]][i] : 0;
            } else {
                trie[atual][i] = trie[link_falho[atual]][i];
            }
        }
    }

    return 0;
}

int resolver(char *s) {
    int atual = 0;
    int resposta = 0;

    for (size_t i = 0; s[i]; ++i) {
        atual = trie[atual][s[i] - 'a'];
        resposta = maximo(resposta, maximo(dp[indice_palavra[atual]], dp[indice_palavra[link_falho[atual]]]));
    }

    return resposta + 1;
}


inline int maximo(int a, int b) {
    return a > b ? a : b;
}