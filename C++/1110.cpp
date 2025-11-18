#include <bits/stdc++.h>

using namespace std;


int main(){

    while(true){
        int n;
        cin >> n;
        if(n == 0) break;

        deque<int> fila;
        vector<int> fora;

        for(int i = n; i > 0; i--){
            fila.push_front(i);
        }

        while(fila.size() > 1){
            int aux = fila.front();
            fila.pop_front();

            fora.push_back(aux);

            aux = fila.front();
            fila.pop_front();

            fila.push_back(aux);



        }

        cout << "Discarded cards: ";
        for(int i = 0; i < fora.size(); i++){
            if(i != fora.size()-1) cout << fora[i] << ", ";
            else cout << fora[i] << endl;
        }

        cout << "Remaining card: " << fila.front() << endl;


    }
}