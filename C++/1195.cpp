#include <iostream>
using namespace std;

class No {
public:
    int valor;
    No *pai, *esq, *dir;

    No(int v) : valor(v), pai(nullptr), esq(nullptr), dir(nullptr) {}
    ~No() {
        delete esq;
        delete dir;
    }
};

class ArvoreBinaria {
private:
    No* topo;

    No* adicionaNo(No* no, int valor) {
        if (!no) {
            return new No(valor);
        } else {
            if (valor < no->valor) {
                no->esq = adicionaNo(no->esq, valor);
                if (no->esq) no->esq->pai = no;
            } else if (valor > no->valor) {
                no->dir = adicionaNo(no->dir, valor);
                if (no->dir) no->dir->pai = no;
            }
        }
        return no;
    }

    No* buscaNo(No* no, int valor) {
        if (!no) return nullptr;
        if (valor < no->valor)
            return buscaNo(no->esq, valor);
        else if (valor == no->valor)
            return no;
        else
            return buscaNo(no->dir, valor);
    }

    void prefixaNo(No* no) {
        if (!no) return;
        cout << " " << no->valor;
        prefixaNo(no->esq);
        prefixaNo(no->dir);
    }

    void infixaNo(No* no) {
        if (!no) return;
        infixaNo(no->esq);
        cout << " " << no->valor;
        infixaNo(no->dir);
    }

    void posfixaNo(No* no) {
        if (!no) return;
        posfixaNo(no->esq);
        posfixaNo(no->dir);
        cout << " " << no->valor;
    }

    void removeNo(No* no) {
        if (!no) return;

        No* pai = no->pai;
        if (!no->esq && !no->dir) {
            if (pai) {
                if (pai->esq == no) pai->esq = nullptr;
                else pai->dir = nullptr;
            }
            delete no;
        } else if (!no->esq || !no->dir) {
            No* filho = no->esq ? no->esq : no->dir;
            if (pai) {
                if (pai->esq == no) pai->esq = filho;
                else pai->dir = filho;
                filho->pai = pai;
            }
            delete no;
        } else {
            No* sucessor = no->dir;
            while (sucessor->esq)
                sucessor = sucessor->esq;
            no->valor = sucessor->valor;
            removeNo(sucessor);
        }
    }

public:
    ArvoreBinaria() : topo(nullptr) {}

    ~ArvoreBinaria() {
        delete topo;
    }

    void adiciona(int valor) {
        topo = adicionaNo(topo, valor);
    }

    bool busca(int valor) {
        return buscaNo(topo, valor) != nullptr;
    }

    void remove(int valor) {
        No* no = buscaNo(topo, valor);
        if (no && !no->pai) {
            if (!no->esq && !no->dir) {
                delete topo;
                topo = nullptr;
            } else if (!no->esq || !no->dir) {
                No* novoTopo = no->esq ? no->esq : no->dir;
                novoTopo->pai = nullptr;
                delete no;
                topo = novoTopo;
            } else {
                removeNo(no);
            }
        } else {
            removeNo(no);
        }
    }

    void prefixa() {
        cout << "Pre.:";
        prefixaNo(topo);
        cout << "\n";
    }

    void infixa() {
        cout << "In..:";
        infixaNo(topo);
        cout << "\n";
    }

    void posfixa() {
        cout << "Post:";
        posfixaNo(topo);
        cout << "\n";
    }
};

int main() {
    int C, N, x;
    cin >> C;

    for (int k = 1; k <= C; ++k) {
        cin >> N;
        ArvoreBinaria ab;

        for (int i = 0; i < N; ++i) {
            cin >> x;
            ab.adiciona(x);
        }

        cout << "Case " << k << ":\n";
        ab.prefixa();
        ab.infixa();
        ab.posfixa();
        cout << "\n";
    }

    return 0;
}
