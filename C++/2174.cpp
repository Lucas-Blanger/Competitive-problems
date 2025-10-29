#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; 
    cin >> n;

    set<string> p;
    for(int i = 0; i < n; i++){
        string pok;
        cin >> pok;
        p.insert(pok);
    }

    int t = p.size();

    cout << "Falta(m) " << 151 - t << " pomekon(s)." << endl;
}