#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;


int main(){
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
       string linha;
       getline(cin,linha);



       for(int j = 0; j < linha.size(); j++){
        if(isalpha(linha[j]) != 0){
            linha[j] = char(int(linha[j]) + 3);
        }
           
       }

   
       reverse(linha.begin(), linha.end());
 

       int met = linha.size() / 2;

       for(int j = met; j < linha.size(); j++){
            linha[j] = linha[j] -1;
       }

       cout << linha << endl;


    
    }
}