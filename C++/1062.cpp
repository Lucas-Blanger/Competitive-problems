#include <bits/stdc++.h>


using namespace std;


int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;



        while(true){
            int x;
            vector<int> como;
            for(int i = 0; i < n; i++){
                cin >> x;
                if(x == 0) break;
                como.push_back(x);
            }
            if(x == 0) break;

            stack<int> estacao;
            bool pass = true;
            int j = 1;
            for(int i = 0; i < n; i++){
                int aux = como[i];
                if(aux == j){
                    j++;
                }else{
                    while((j <= n && (estacao.empty() || estacao.top() != aux))){
                        estacao.push(j);
                        j++;
                    }
                    if(!estacao.empty() && estacao.top() == aux){
                        estacao.pop();
                    }else{
                        pass = false;
                        break;
                    }
                }
            }
            if(pass) cout << "Yes" << endl;
            else cout << "No" << endl;

        }
        cout << endl;
    }
}