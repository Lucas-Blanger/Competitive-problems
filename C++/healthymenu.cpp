#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;

    cin >> n >> k;

    int mat[n][k];


    int alunos = 0;

    for(int i = 0; i < n; i++){
        for(int j=0; j < k; j++){
            cin >> mat[i][j];

        }
    }

    for(int j = 0; j < k; j++){
        int maior = 0;
        for(int i = 0; i < n; i++){
            if(mat[i][j] > maior) maior = mat[i][j];
        }
        alunos += maior;
    }

    cout << alunos << endl;

}