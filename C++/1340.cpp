#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        bool ehPilha = true, ehFila = true, ehFilaP = true;

        stack<int> pilha;
        queue<int> fila;
        priority_queue<int> pq;

        for(int i = 0; i < n;i++){
            int op,x;
            cin >> op >> x;

            if(op == 1){
                if(ehPilha) pilha.push(x);
                if(ehFila) fila.push(x);
                if(ehFilaP) pq.push(x);
            }else{
                if(ehPilha && !pilha.empty()){
                    if(pilha.top() == x) pilha.pop();
                    else ehPilha = false;
                } else ehPilha = false;

                if(ehFila && !fila.empty()){
                    if(fila.front() == x) fila.pop();
                    else ehFila = false;
                } else ehFila = false;

                if(ehFilaP && !pq.empty()){
                    if(pq.top() == x) pq.pop();
                    else ehFilaP = false;
                } else ehFilaP = false;

            }
        }

        if(ehFila && ehPilha && ehFilaP) cout << "not sure" << endl;
        else if(ehFila && ehPilha || ehPilha && ehFilaP || ehFila && ehFilaP) cout << "not sure" << endl;
        else if(ehPilha) cout << "stack" << endl;
        else if(ehFila) cout << "queue" << endl;
        else if(ehFilaP) cout << "priority queue" << endl;
        else cout << "impossible" << endl;
    
    }
}
