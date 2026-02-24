#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int d, n;
        cin >> d >> n;
        
        int cents = d * 100;
        int troco = 0;  
        
        for(int i = 0; i < n; i++) {
            double preco;
            cin >> preco;
            
            int centsPreco = (int)round(preco * 100);
            
            int quant = cents / centsPreco;
            
            if(quant >= 1) {
                int gasto = quant * centsPreco;
                int trocoAtual = cents - gasto;  
                troco = max(troco, trocoAtual);  
            }
        }
        
        cout << fixed << setprecision(2) << (troco / 100.0) << endl;
    }
    
}