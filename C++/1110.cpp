#include <bits/stdc++.h>

using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;

        deque<int> pilha;
        deque<int> fora;
        for(int i = n; i >= 1; i--){
            pilha.push_back(i);
        }

        while(pilha.size() >= 2){

            fora.push_back(pilha.back());
            pilha.pop_back();


            int aux = pilha.back();
            pilha.pop_back();

            pilha.push_front(aux);
        }

        cout << "Discarded cards: ";
        int t = fora.size();
        for(int i = 0; i < t ; i++){
            if(i ==  t-1){
                cout << fora.front() << endl;
                fora.pop_front();
            } else {
                cout << fora.front() << ", ";
                fora.pop_front();
            }
        }
       
       cout << "Remaining card: " << pilha.front() << endl;



    }
}