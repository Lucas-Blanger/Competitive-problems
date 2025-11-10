#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string entrada;
        cin >> entrada;
        stack<char> d;
        int r = 0;
        for(int j = 0; j < entrada.size();j++){
            if(entrada[j] == '>' && !d.empty()){
                if(d.top() == '<'){
                    r++;
                    d.pop();
                }else{
                    d.push(entrada[j]);
                }
            }else if(entrada[j] == '<') d.push(entrada[j]);

        }
        cout << r << endl;
    
    }
}