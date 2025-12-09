#include <bits/stdc++.h>



using namespace std;

int main() {
    string ex;
    
    while(getline(cin, ex)) {
        bool lexi = false;
        for(int i = 0; i < ex.length(); i++) {
            char c = ex[i];
            if(c == ' ') continue;
            
            bool pass = (c >= 'a' && c <= 'z') || 
                        (c >= 'A' && c <= 'Z') || 
                        (c >= '0' && c <= '9') ||
                        c == '+' || c == '-' || c == '*' || c == '/' || c == '^' ||
                        c == '>' || c == '<' || c == '=' || c == '#' ||
                        c == '.' || c == '|' || c == '(' || c == ')';
            
            if(!pass) {
                lexi = true;
                break;
            }
        }
        
        if(lexi) {
            cout << "Lexical Error!" << endl;
            continue;
        }
        
        stack<char> pi;
        string r = "";
        char last = '\0';
        bool sytanx = false;
        
        for(int i = 0; i < ex.length(); i++) {
            char c = ex[i];
            
            if(c == ' ') continue;
            
            bool operando = (c >= 'a' && c <= 'z') || 
                            (c >= 'A' && c <= 'Z') || 
                            (c >= '0' && c <= '9');
            
            bool operador = c == '^' || c == '*' || c == '/' || 
                             c == '+' || c == '-' || c == '>' || 
                             c == '<' || c == '=' || c == '#' || 
                             c == '.' || c == '|';
            
            if(operando) {
                bool aux = (last >= 'a' && last <= 'z') || 
                                     (last >= 'A' && last <= 'Z') || 
                                     (last >= '0' && last <= '9');
                
                if(aux) {
                    sytanx = true;
                    break;
                }
                r += c;
                last = c;
            }
            else if(c == '(') {
                pi.push(c);
                last = c;
            }
            else if(c == ')') {
                bool lasOperador = last == '^' || last == '*' || last == '/' || 
                                      last == '+' || last == '-' || last == '>' || 
                                      last == '<' || last == '=' || last == '#' || 
                                      last == '.' || last == '|';
                
                if(lasOperador || last == '(') {
                    sytanx = true;
                    break;
                }
                
                bool found = false;
                while(!pi.empty()) {
                    if(pi.top() == '(') {
                        pi.pop();
                        found = true;
                        break;
                    }
                    r += pi.top();
                    pi.pop();
                }
                
                if(!found) {
                    sytanx = true;
                    break;
                }
                last = c;
            }
            else if(operador) {
                bool lasOperador = last == '^' || last == '*' || last == '/' || 
                                      last == '+' || last == '-' || last == '>' || 
                                      last == '<' || last == '=' || last == '#' || 
                                      last == '.' || last == '|';
                
                if(lasOperador || last == '(' || last == '\0') {
                    sytanx = true;
                    break;
                }
                
                int precC;
                if(c == '^') precC = 6;
                else if(c == '*' || c == '/') precC = 5;
                else if(c == '+' || c == '-') precC = 4;
                else if(c == '>' || c == '<' || c == '=' || c == '#') precC = 3;
                else if(c == '.') precC = 2;
                else if(c == '|') precC = 1;
                else precC = 0;
                
                while(!pi.empty() && pi.top() != '(') {
                    char topOp = pi.top();
                    
                    int precTop;
                    if(topOp == '^') precTop = 6;
                    else if(topOp == '*' || topOp == '/') precTop = 5;
                    else if(topOp == '+' || topOp == '-') precTop = 4;
                    else if(topOp == '>' || topOp == '<' || topOp == '=' || topOp == '#') precTop = 3;
                    else if(topOp == '.') precTop = 2;
                    else if(topOp == '|') precTop = 1;
                    else precTop = 0;
                    
                    if(precTop >= precC) {
                        r += pi.top();
                        pi.pop();
                    } else {
                        break;
                    }
                }
                
                pi.push(c);
                last = c;
            }
        }
        
        if(sytanx) {
            cout << "Syntax Error!" << endl;
            continue;
        }
        
        bool lasOperador = last == '^' || last == '*' || last == '/' || 
                              last == '+' || last == '-' || last == '>' || 
                              last == '<' || last == '=' || last == '#' || 
                              last == '.' || last == '|';
        
        if(lasOperador || last == '(') {
            cout << "Syntax Error!" << endl;
            continue;
        }
        
        while(!pi.empty()) {
            if(pi.top() == '(') {
                sytanx = true;
                break;
            }
            r += pi.top();
            pi.pop();
        }
        
        if(sytanx) {
            cout << "Syntax Error!" << endl;
        } else {
            cout << r << endl;
        }
    }
    

}