#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> mu(n);
    
    for(int i = 0; i < n; i++){
        cin >> mu[i];
    }
    
    int maior = 0;
    
    for(int i = n-1; i >= 0; i--){
        multiset<int> valores;
        
        for(int p = 0; p < n; p++){
            valores.insert(mu[p]);
        }
        
        int temp = k;
        
        for(int j = i; j >= 0 && temp > 0; j--){
            valores.erase(valores.find(mu[j]));
            valores.insert(mu[j] + temp);
            temp--;
        }
        
        int menor = *valores.begin();
        maior = max(maior, menor);
    }
    
    cout << maior << endl;
    

}