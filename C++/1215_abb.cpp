#include <iostream>
#include <cstdlib>

#define TIPO string

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

void infixa ( nodo *tree) {
    if ( tree != NULL ) {
        infixa(tree->esquerda ); ///perc sub-arvore esquerda
        cout << tree->informacao << endl;
        infixa(tree->direita); ///perc rec. sub-arvore direita
    }
}

int main() {
    // freopen("arvore.in", "r", stdin);

    string linha;
    nodo *raiz = 0;
    while(getline(cin,linha)){
        string palavra = "";

        for(int i = 0; i < linha.size(); i++){
            if(isalpha(linha[i])) palavra += tolower(linha[i]);
            else{
                if(!palavra.empty()){
                    raiz = insere(raiz, palavra);
                    palavra = "";
                }
            }
        }
        if(!palavra.empty()) raiz = insere(raiz, palavra);
        
    }
    infixa(raiz);


}