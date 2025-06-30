#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;


int main () {
    int n;

    while(true){
        cin >> n;
        if(n == 0){
            break;
        }
        int mat[n][n];

        int cont = 1;
       
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                mat[i][j] = cont;
                cont++;
            }
            cont = 1;
        }
        

        int aux;
        cont = 2;
        aux = 2;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                mat[i][j] = cont;
                cont--;
            }
            aux++;
            cont = aux;
        }



        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j != 0){
                    cout << " ";
                }
                cout << setw(3) << mat[i][j];
            }
            cout << endl;
        }
        cout << endl;



    }
 


}
    




