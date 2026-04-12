#include <bits/stdc++.h>

using namespace std;

int main() {
    
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;

        queue<char> a;
        for(int i = 0; i < n; i++){
            char x;
            cin >> x;
            a.push(x);
        }

        queue<char> b;
        for(int i = 0; i < n; i++){
            char x;
            cin >> x;
            b.push(x);
        }

        string r = "";
        stack<char> aux;
        bool pass = true;

        while(true){
            if(!aux.empty() && !b.empty() && aux.top() == b.front()){
                aux.pop();
                b.pop();
                r += 'R';
            }else if(!a.empty()){
                aux.push(a.front());
                a.pop();
                r += 'I';
            }else{
                break;
            }

            if(a.empty() && !aux.empty() && !b.empty() && aux.top() != b.front()){
                pass = false;
                break;
            }
        }
        if(pass) cout << r << endl;
        else cout << r << " Impossible" << endl;
       
    }
}
