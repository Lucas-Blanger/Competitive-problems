#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;


int main () {
    int n;
    while(cin >> n){
        int mat[n][n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mat[i][j] = 3;
            }
        }

        for(int i = 0; i < n; i++){
            mat[i][i] = 1;
        }

        for(int i = 0; i < n; i++){
            mat[i][n - i - 1] = 2;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << mat[i][j];
            }
            cout << endl;
        }


    }
 

}
    




