#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;


int main () {
    int n;
    while (cin >> n){
        int mat[n][n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mat[i][j] = 0;
            }
        }

        //diagonal principal com 2
        for(int i = 0; i < n; i++){
            mat[i][i] = 2;
        }
        //diagonal secundaria com 3
        for(int i = 0; i < n; i++){
            mat[i][n - i - 1] = 3;
        }
        for(int i = n / 3; i < n - n / 3; i++){
            for(int j = n / 3; j < n - n / 3; j++){
                mat[i][j] = 1;
            }
        }
        mat[n/2][n/2] = 4;

        for(int i = 0; i < n;i++){
            for(int j = 0; j < n; j++){
                cout << mat[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    

}
    




