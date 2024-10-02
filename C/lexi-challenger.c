#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char s[100001];
    int k;
    
    scanf("%s", s);
    scanf("%d", &k);
    
    int n = strlen(s);
    bool temp[n];

    for (int i = 0; i < n; i++) {
        temp[i] = false;
    }
    
    for (int i = 0; i < k; i++) {
        if (!temp[i]) {
            int ciclo[100001], cicloTamanho = 0;
            
            for (int j = i; j < n; j += k) {
                ciclo[cicloTamanho++] = j;
                temp[j] = true;
            }
            
            for (int x = 0; x < cicloTamanho - 1; x++) {
                for (int y = x + 1; y < cicloTamanho; y++) {
                    if (s[ciclo[x]] > s[ciclo[y]]) {
                        char temp2 = s[ciclo[x]];
                        s[ciclo[x]] = s[ciclo[y]];
                        s[ciclo[y]] = temp2;
                    }
                }
            }
        }
    }
    
    printf("%s\n", s);

}
