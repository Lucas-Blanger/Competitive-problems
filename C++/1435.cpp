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


        n = n;
        int mat[n][n];
        int x;

        x = n - 2;
        int number = 1, comeca = 0;
        if(n > 3) {
            while(x != 0){
                for(int i = comeca; i < n - comeca; i++){
                    for(int j = comeca; j < n - comeca; j++){
                        mat[i][j] = number;
                    }
                }
                x--;
                number++;
                comeca++;
            }
        } else {
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n;j++){
                    mat[i][j] = 1;
                }
            }
            if(n == 3){
                mat[1][1] = 2;
            }
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
    




