#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char grid[10][10];
    
    // Inicializa o grid com 'x'
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            grid[i][j] = 'x';

    cin >> n;
    bool passou = true;

    for(int i = 0; i < n; i++){
        int d, l, r, c;
        cin >> d >> l >> r >> c;
        r--; c--; 

        if(d == 0){
            if(c + l > 10){
                passou = false;
                break;
            }
            for(int j = 0; j < l; j++){
                if(grid[r][c+j] != 'x'){
                    passou = false;
                    break;
                }
            }
            if(passou){
                for(int j = 0; j < l; j++){
                    grid[r][c+j] = 'o';
                }
            }
        }else{
            if(r + l > 10){
                passou = false;
                break;
            }
            for(int j = 0; j < l; j++){
                if(grid[r+j][c] != 'x'){
                    passou = false;
                    break;
                }
            }
            if(passou){
                for(int j = 0; j < l; j++){
                    grid[r+j][c] = 'o';
                }
            }
        }
    }

    cout << (passou ? 'Y' : 'N') << endl;
}
