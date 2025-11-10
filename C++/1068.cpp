#include <bits/stdc++.h>

using namespace std;


int main(){
    string expressao;
    while(cin >> expressao){
        stack<char> ex;


        for(int i = 0; i < expressao.size(); i++){
            if(expressao[i] == '(' || expressao[i] == ')'){
                if(expressao[i] == ')' && ex.empty() == false){
                    if(ex.top() == '(') {
                        ex.pop();
                    } else {
                        ex.push(expressao[i]);
                    }
                }else{
                    ex.push(expressao[i]);
                }

            }else{
                if(expressao[i] == ')' || expressao[i] == '(') ex.push(expressao[i]);

            }
        }
        if(ex.empty()) cout << "correct" << endl;
        else cout << "incorrect" << endl;
    
    }
}