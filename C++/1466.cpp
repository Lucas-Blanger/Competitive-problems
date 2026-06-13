#include <iostream>
#include <cstdlib>
#include <queue>

#define TIPO int

using namespace std;

struct nodo {
    nodo *esquerda;
    TIPO informacao;
    nodo *direita;

    nodo(TIPO info)
        : informacao(info),
          esquerda(0),
          direita(0) {}
};

nodo *P;


struct nodo *insere(nodo *tree, TIPO informacao) {
    if (tree == NULL)
        tree = new nodo(informacao);
    else if (informacao < tree->informacao)
        tree->esquerda = insere(tree->esquerda, informacao);
    else if (informacao > tree->informacao)
        tree->direita = insere(tree->direita, informacao);

    return tree;
}

struct nodo *GetMax(nodo *tree) {
    if (tree->direita == NULL) {
        P = tree;
        tree = tree->esquerda;
    } else {
        tree->direita = GetMax(tree->direita);
    }

    return tree;
}

struct nodo *retira(nodo *tree, TIPO informacao) {
    if (tree == NULL) {
        cout << "Informacao nao encontrada" << endl;
    } else {
        if (informacao == tree->informacao) {
            if (tree->esquerda == NULL) {
                tree = tree->direita;
            } else {
                if (tree->direita == NULL) {
                    tree = tree->esquerda;
                } else {
                    tree->esquerda = GetMax(tree->esquerda);
                    tree->informacao = P->informacao;
                }

                free(P);
            }
        } else {
            if (informacao < tree->informacao) {
                tree->esquerda = retira(tree->esquerda, informacao);
            } else {
                tree->direita = retira(tree->direita, informacao);
            }
        }
    }

    return tree;
}
void infixa(nodo *tree) {
    if (tree != NULL) {
        infixa(tree->esquerda); // percorre subárvore esquerda
        cout << tree->informacao << " ";
        infixa(tree->direita);  // percorre subárvore direita
    }
}


void bfs(nodo *tree) {
    if (tree == NULL) return;

    queue<nodo*> fila;
    fila.push(tree);

    bool first = true;


   while (!fila.empty()) {
        nodo *atual = fila.front();
        fila.pop();

        if(!first) cout << " " << atual->informacao;
        else cout << atual->informacao;
       
        first = false;

        if (atual->esquerda != NULL) fila.push(atual->esquerda);

        if (atual->direita != NULL) fila.push(atual->direita);
    }
        
}

int main() {
    // freopen("arvore.in", "r", stdin);
    int c, casos = 0;
    cin >> c;
    while(c--){
        nodo *raiz = 0;
        TIPO valor;
        casos++;
        int elementos;

        cin >> elementos;

        while (elementos--) {
            cin >> valor;
            raiz = insere(raiz, valor);
        }
        cout << "Case " << casos << ":" << endl;
        bfs(raiz);
        cout << endl;
        cout << endl;

    }
}