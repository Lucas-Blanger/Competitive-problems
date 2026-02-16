#include <bits/stdc++.h>

using namespace std;

struct Child {
    string name;
    int value;
    int prev, next;
};

int main() {

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        Child child[100];

        for (int i = 0; i < n; ++i) {
            cin >> child[i].name >> child[i].value;

            child[i].prev = (i - 1 + n) % n;
            child[i].next = (i + 1) % n;
        }

        int i = 0;

        while (n > 1) {
            int value = child[i].value;

            if (value % 2) {
                for (int j = 0; j < value; ++j)
                    i = child[i].next;
            } else {
                for (int j = 0; j < value; ++j)
                    i = child[i].prev;
            }

            child[child[i].prev].next = child[i].next;
            child[child[i].next].prev = child[i].prev;

            --n;
        }

        i = child[i].next;

        cout << "Vencedor(a): " << child[i].name << endl;
    }

}
