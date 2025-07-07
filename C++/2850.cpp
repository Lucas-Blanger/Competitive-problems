#include <iostream>
#include <string>

using namespace std;

int main(){
    string entrada;
    
    while (getline(cin, entrada)){
        if (entrada == "direita"){
            cout << "frances" << endl;
        }else if (entrada == "esquerda"){
            cout << "ingles" << endl;
        }else if (entrada == "nenhuma"){
            cout << "portugues" << endl;

        }else if (entrada == "as duas"){
            cout << "caiu" << endl;

        }
            
        fflush(stdin);
    }

}