#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        stack<int> pilha;
        queue<int> fila;
        priority_queue<int> fila_p;

        bool is_stack = true, is_queue = true, is_pq = true;

        for (int i = 0; i < n; ++i) {
            int op, x;
            cin >> op >> x;

            if (op == 1) {
                if (is_stack) pilha.push(x);
                if (is_queue) fila.push(x);
                if (is_pq) fila_p.push(x);
            } else {
                if (is_stack) {
                    if (pilha.empty() || pilha.top() != x) is_stack = false;
                    else pilha.pop();
                }
                if (is_queue) {
                    if (fila.empty() || fila.front() != x) is_queue = false;
                    else fila.pop();
                }
                if (is_pq) {
                    if (fila_p.empty() || fila_p.top() != x) is_pq = false;
                    else fila_p.pop();
                }
            }
        }

        if (is_stack + is_queue + is_pq == 0) {
            cout << "impossible\n";
        } else if (is_stack + is_queue + is_pq > 1) {
            cout << "not sure\n";
        } else if (is_stack) {
            cout << "stack\n";
        } else if (is_queue) {
            cout << "queue\n";
        } else if (is_pq) {
            cout << "priority queue\n";
        }
    }
}
