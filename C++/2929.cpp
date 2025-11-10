#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    stack<int> pilha;
    stack<int> menor;
    
    for(int i = 0; i < n; i++){
        char operacao[10];
        scanf("%s", operacao);
        
        if(operacao[1] == 'U'){  
            int valor;
            scanf("%d", &valor);
            pilha.push(valor);
            
            if(menor.empty() || valor <= menor.top()){
                menor.push(valor);
            }
     
        }else if(operacao[1] == 'O'){ 
            if(pilha.empty()){
                printf("EMPTY\n");
            }else{
                if(pilha.top() == menor.top()){
                    menor.pop();
                }
                pilha.pop();
            }
            
        }else{  
            if(pilha.empty()){
                printf("EMPTY\n");
            }else{
                printf("%d\n", menor.top());
            }
        }
    }

}