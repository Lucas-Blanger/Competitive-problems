#include <iostream>
#include <cstdlib>
#include <queue>

#define TIPO char

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

void infixa ( nodo *tree, string &caminho ) {
    if ( tree != NULL ) {
        infixa(tree->esquerda, caminho ); ///perc sub-arvore esquerda
        caminho += tree->informacao;
        caminho += " ";
        infixa(tree->direita, caminho); ///perc rec. sub-arvore direita
    }
}
void prefixa ( nodo *tree, string &caminho ) {
    if ( tree != NULL ) {
        caminho += tree->informacao;
        caminho += " ";
        prefixa(tree->esquerda, caminho ); ///perc sub-arvore esquerda
        prefixa(tree->direita, caminho); ///perc rec. sub-arvore direita
    }
}

void posfixa ( nodo *tree, string &caminho ) {
    if ( tree != NULL ) {
        posfixa(tree->esquerda,caminho ); ///perc sub-arvore esquerda
        posfixa(tree->direita, caminho); ///perc rec. sub-arvore direita
        caminho += tree->informacao;
        caminho += " ";
    }
}

bool pesquisa(nodo *tree, char y){
    if(tree == NULL) return false;

    if(tree->informacao == y) return true;

    if(pesquisa(tree->esquerda,y)) return true;

    if(pesquisa(tree->direita,y)) return true;

    return false;
}

int main() {
    // freopen("arvore.in", "r", stdin);
    nodo *raiz = 0;

    string linha;
    while(cin >> linha){
        string caminho = "";
        if(linha == "I"){
            char a;
            cin >> a;
            raiz = insere(raiz,a);
        }else if(linha == "INFIXA"){
            infixa(raiz, caminho);
            caminho.pop_back();
            cout << caminho << endl;
        } else if(linha == "PREFIXA"){
            prefixa(raiz, caminho);
            caminho.pop_back();
            cout << caminho << endl;
        } else if(linha == "POSFIXA"){
            posfixa(raiz, caminho);
            caminho.pop_back();
            cout << caminho << endl;
        }else if(linha == "P"){
            char t;
            cin >> t;
            bool r = pesquisa(raiz,t);
            if(r) cout << t << " existe" << endl;
            else cout << t << " nao existe" << endl;

        }
    }

}