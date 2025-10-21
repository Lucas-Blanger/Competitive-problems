#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;


int main(){
    int n;
    cin >> n;

    
    for(int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;

        int pos = b.size();
        if(a.size() < b.size()){
            cout << "nao encaixa" << endl;
            continue;
        }
        string aux = a.substr(a.size()-pos, pos);


        if(aux == b) cout << "encaixa" << endl;
        else cout << "nao encaixa" << endl;
    
    }
}