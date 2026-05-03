#include <bits/stdc++.h>
using namespace std;


int main(){
    //+,-,*,/,^, 
    
    map<char, int> pos;
    
    pos['^'] = 5;
    pos['/'] = 4;
    pos['*'] = 4;
    pos['+'] = 2;
    pos['-'] = 2;
    pos['('] = 1;


    int n;
    cin >> n;
    while(n--){
        string op;
        cin >> op;

        string r = "";
        stack<char> pilha;
        for(int i = 0; i < op.size(); i++){
            //letra
            if(isalnum(op[i])) r += op[i];
            else if(op[i] == '(') pilha.push('(');
            else if(op[i] == ')'){
                while(!pilha.empty() && pilha.top() != '('){
                    r += pilha.top();
                    pilha.pop();
                }
                pilha.pop(); // tirar o (
            }else{
                
                if(pilha.empty())  pilha.push(op[i]);
                else if(!pilha.empty() && pos[op[i]] > pos[pilha.top()]) pilha.push(op[i]);
                else{
                    while(!pilha.empty() && pos[op[i]] <= pos[pilha.top()]){
                        r += pilha.top();
                        pilha.pop();
                    }
                    pilha.push(op[i]);
                }
            }

        }
        while(!pilha.empty()){
            r+= pilha.top();
            pilha.pop();
        }

        cout << r << endl;
    }
}