#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> pol(n+1,0);

    for(int i = n; i >= 0; i--){
        cin >> pol[i];
    }


    int p = 0;
    while(pol.size() > 1 || pol[0] != 1){
        p++;

        while (pol.size() > 1 && pol.back() == 0) {
            pol.pop_back();
        }

        
        if(pol[0] == 1){
            vector<int> aux(pol.size()+1,0);

            for (int i = 0; i < pol.size(); i++) {
                aux[i] += pol[i];      
                aux[i + 1] += pol[i]; 
            }

            aux[0] += 1;

            for (int i = 0; i < aux.size(); i++) {
                if (aux[i] == 2) {
                    aux[i] = 0;
                }
            }

            pol = aux;
        }else{
            for (int i = 1; i < pol.size(); i++) {
                pol[i-1] = pol[i];
            }
            pol.pop_back();
        }
    }

    cout << p << endl;
}