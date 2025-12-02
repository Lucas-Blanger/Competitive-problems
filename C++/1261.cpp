#include <bits/stdc++.h>


using namespace std;

int main(){
  int m, n;
  cin >> m >> n;
  map<string, int> cargos;


  for(int i = 0; i < m; i++){
      string nome;
      int valor;
      cin >> nome >> valor;
      cargos[nome] = valor;
  }

  for(int i = 0; i < n; i++){
      string linha, texto;
      while(getline(cin, linha)){
         if(linha[0] == '.') break;
         texto += linha;
         texto += " ";
      }
      int preco = 0;
      stringstream ss(texto);
      string aux;
      while(ss >> aux){
         preco += cargos[aux];
      }

      cout << preco << endl;
  }
   

}