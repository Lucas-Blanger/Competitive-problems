#include <bits/stdc++.h>


using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int c;
    cin >> c;

    while(c--){
        int b,e;
        cin >> b >> e;
        string cres = "";
        string descre = "";

        for(int i = b; i <= e; i++){
            cres += to_string(i);
        }
        for(int i = e; i >= b; i--){
            string aux = to_string(i);
            reverse(aux.begin(), aux.end());
            descre += aux;
        }

        cout << cres << descre << endl;
    }
    
    
}