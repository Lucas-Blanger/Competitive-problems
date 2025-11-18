#include <bits/stdc++.h>

using namespace std;


int main(){
    string expressao;
    while(cin >> expressao){
        stack<char> pilha;

        for(int i = 0; i < expressao.size(); i++){
            if(expressao[i] == '(' || expressao[i] == ')') {
                if(pilha.empty()) pilha.push(expressao[i]);
                else{
                    if(pilha.top() == '(' && expressao[i] == ')'){
                        pilha.pop();
                    }else{
                        pilha.push(expressao[i]);
                    }
                }

            }
        }

        if(!pilha.empty()){
            cout << "incorrect" << endl;
        } else cout << "correct" << endl;


    }
    
}