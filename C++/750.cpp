#include <bits/stdc++.h>


using namespace std;

int lFixa, cFixa;
int tabu[9];
bool usado[9];
bool diag1[20];
bool diag2[20];

int cont;

void backtrack(int col){
    if(col == 9){
        cont++;
        cout << setw(2) << cont << "      ";
        for(int i = 1; i <= 8; i++){
            if(i == 8){
                cout << tabu[i] << endl;
            }else{
                cout << tabu[i] << " ";
            }
            
        }
        return;
    }

    if(col == cFixa){
        int linha = lFixa;

        if(!usado[linha] && !diag1[linha - col + 8] && !diag2[linha+col]){
            tabu[col] = linha;
            usado[linha] = true;
            diag1[linha - col + 8] = true;
            diag2[linha+col] = true;
            backtrack(col+1);

            usado[linha] = false;
            diag1[linha - col + 8] = false;
            diag2[linha+col] = false;
        
        }
        return;
    }

    for(int linha = 1; linha <= 8; linha++){
        if(!usado[linha] && !diag1[linha - col + 8] && !diag2[linha+col]){
            tabu[col] = linha;
            usado[linha] = true;
            diag1[linha - col + 8] = true;
            diag2[linha+col] = true;

            backtrack(col+1);

            usado[linha] = false;
            diag1[linha - col + 8] = false;
            diag2[linha+col] = false;
        
        }
    }

}

int main() {

    int t;
    cin >> t;

    while (t--) {
        cont = 0;
        cin >> lFixa >> cFixa;

        for(int i = 0; i < 9; i++){
            usado[i] = false;
        }

        for(int i = 0; i < 20; i++){
            diag1[i] = false;
            diag2[i] = false;
        }
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";

        backtrack(1);

        if (t) cout << "\n";

        

    }

}


