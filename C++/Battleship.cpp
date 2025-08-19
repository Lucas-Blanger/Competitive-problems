#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int mar[10][10];
    bool passou = true;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            mar[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        int d,l,r,c;
        cin >> d >> l >> r >> c;
        if(d == 0){
            if(r > 10 || r < 0 || c > 10 || c < 0 || c+ l-1 > 10 || c+ l-1 < 0 ){
                passou = false;
                break;
            }
            for(int i = c; i <= c+l-1; i++){
                if(mar[r][i] == 1){
                    passou = false;
                    break;
                }
            }
            for(int i = c; i <= c+l-1; i++){
                mar[r][i] = 1;
            }
        }else if(d == 1){
            if(r > 10 || r < 0 || c > 10 || c < 0 || r+l-1 > 10 || r+l-1 < 0 ){
                passou = false;
                break;
            }
            for(int i = r; i <= r+l-1; i++){
                if(mar[i][c] == 1){
                    passou = false;
                    break;
                }
            }
            for(int i = r; i <= r+l-1; i++){
                mar[i][c] = 1;
            }

        }
    }
    if (passou){
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }

   
}
