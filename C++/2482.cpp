#include <bits/stdc++.h>


using namespace std;

int main(){
   int n;
   cin >> n;

   map<string, string> natal;
   cin.ignore();

   for(int i = 0; i < n; i++){
        string a, b;
        getline(cin, a);
        getline(cin, b);
        natal[a] = b;
   }

   int m;
   cin >> m;
   cin.ignore();
   map<string, string> feliz;
   map<string, string>::iterator it;



   for(int i = 0; i < m; i++){
        string nome, idioma;
        getline(cin, nome);
        getline(cin, idioma);
        cout << nome << endl;
        cout << natal[idioma] << endl;
        cout << endl;
   }





}