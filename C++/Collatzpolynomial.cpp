#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> pol(n+1,0);

    for (int i = n; i >= 0; i--) {
        cin >> pol[i];
    }

    int r = 0;
    while(pol.size() != 1 || pol[0] != 1){
        r++;
        int t = pol.size();
        
        while (pol.size() > 1 && pol.back() == 0) {
            pol.pop_back();
        }

        if(pol[0]){
            // Multiplica por (x+1) e soma 1
            vector<int> aux(pol.size() + 1, 0);

            for (int i = 0; i < pol.size(); i++) {
                aux[i + 1] += pol[i];
            }
             for (int i = 0; i < pol.size(); i++) {
                aux[i] += pol[i];
            }
            
            aux[0] += 1;
            
            for (int i = 0; i < aux.size(); i++) {
                aux[i] %= 2;
            }
            
            pol = aux;
            
        
        }else{
            pol.erase(pol.begin());
        }


    }
    cout << r << endl;
   
    
}