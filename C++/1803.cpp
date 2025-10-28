#include <bits/stdc++.h>
#define MOD (int)(1e9 + 7)

using namespace std;


int main(){

    string n1,n2,n3,n4;
    cin >> n1 >> n2 >> n3 >> n4;

    char a,b,c;

    string aux;
    aux.push_back(n1[0]);
    aux.push_back(n2[0]);
    aux.push_back(n3[0]);
    aux.push_back(n4[0]);
    long long f = stoll(aux);



    aux = "";
    int pos = n1.size() -1;
    aux.push_back(n1[pos]);
    aux.push_back(n2[pos]);
    aux.push_back(n3[pos]);
    aux.push_back(n4[pos]);

    long long l = stoll(aux);


    string r = "";

    for(int j = 1; j < pos; j++){
        aux = "";
        aux.push_back(n1[j]);
        aux.push_back(n2[j]);
        aux.push_back(n3[j]);
        aux.push_back(n4[j]);
        long long mi = stoll(aux);

        long long ci = (f * mi + l) % 257;
        cout << (char)ci;
        
    }
    cout << endl;

    
}

