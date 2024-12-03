#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int n; 
    scanf("%d", &n);

    int m = n - 1; 
    int supervisor[MAX] = {0}; 
    int subordinados[MAX] = {0}; 


    for (int i = 0; i < m; i++) {
        int u, v; 
        scanf("%d %d", &u, &v);
        supervisor[u] = v; 
    }

    for (int i = 1; i <= n; i++) {
        if (supervisor[i] != 0) {
            subordinados[supervisor[i]]++;
        }
    }

    for (int i = n; i >= 1; i--) {
        if (supervisor[i] != 0) {
            subordinados[supervisor[i]] += subordinados[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", subordinados[i]);
    }

}
