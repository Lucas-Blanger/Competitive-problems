#include <iostream>

using namespace std;


int main(){
    string texto;
    cin >> texto;
    int direita = 0, esquerda = 0, GD = 0, GE = 0;
    char sacou = 'E';

    for(int i = 0; i < texto.size(); i++){

        if(texto[i] == 'Q'){
            if(GE == 2){
                cout << GE << " (winner) - "  << GD << endl;
                break;
            } else if(GD == 2){
                cout << GE << " - "  << GD << " (winner)" << endl;
                break;
            }
            if(sacou == 'E'){
                cout << GE << " " << "(" << esquerda << "*)" << " - " << GD << " " << "(" << direita << ")" << endl;
                continue;
            } else{
                cout << GE << " " << "(" << esquerda << ")" << " - " << GD << " " << "(" << direita << "*)" << endl;
                continue;
            }
        }
        if(texto[i] == 'S' && sacou == 'E'){
            esquerda++;
            sacou = 'E';
        }else if(texto[i] == 'S' && sacou == 'D'){
            direita++;
            sacou = 'D';
        } else if(texto[i] == 'R' && sacou == 'E'){
            direita++;
            sacou = 'D';
        } else if(texto[i] == 'R' && sacou == 'D'){
            esquerda++;
            sacou = 'E';
        }
        if((direita >= 5 && direita - esquerda >= 2) || direita == 10){
            GD++;
            sacou = 'D';
            direita = 0;
            esquerda = 0;
        } else if((esquerda >= 5 && esquerda - direita >= 2) || esquerda == 10){
            GE++;
            sacou = 'E';
            direita = 0;
            esquerda = 0;
        }
        


    }


}