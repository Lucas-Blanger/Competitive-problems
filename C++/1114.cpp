#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int senhaCorreta = 2002, senha = 0;
    while(senha != senhaCorreta){
        cin >> senha;
        if(senha == senhaCorreta){
            cout << "Acesso Permitido" << endl;
        } else {
            cout << "Senha Invalida" << endl;
        }
    }


}
