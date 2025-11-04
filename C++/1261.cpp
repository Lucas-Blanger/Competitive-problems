#include <bits/stdc++.h>


using namespace std;

int main(){
   int m, n;
   cin >> m >> n;
   
   map<string, long long> dic;
   for(int i = 0; i < m; i++){
      string cargo;
      long long sal;
      cin >> cargo >> sal;
      dic[cargo] = sal;
   }
   
   cin.ignore(); 
   
   for(int i = 0; i < n; i++){
      string descricao = "";
      
      while(true){
         string linha;
         getline(cin, linha);
         
         if(linha == ".") break;
         
         descricao += linha + " "; 
      }
      
      stringstream ss(descricao);
      string palavra;
      long long total = 0;
      
      while(ss >> palavra){
         total += dic[palavra]; 
      }
      
      cout << total << endl;
   }
   

}