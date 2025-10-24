#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    for(int i = 0; i < n; i++){
        string texto;
        getline(cin, texto);
        string palavra = "";
        
        for(int j = 0; j < texto.size(); j++){
            if(j == 0 && isalpha(texto[j])){
                palavra += texto[j];
            }else{
                if(j > 0){
                    if(isalpha(texto[j]) && texto[j-1] == ' ' ){
                        palavra += texto[j];
                    }

                }
            }
           
            
        }
        if(palavra == ""){
            cout << endl;
        }else{
            cout << palavra << endl;
        }
    }
    
}