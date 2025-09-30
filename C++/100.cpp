#include <bits/stdc++.h>


using namespace std;

int main(){
    int i, j;

    while(cin >> i >> j){
        int inicio, fim;
        if(i > j ){
            inicio = j;
            fim = i;
        }else{
            inicio = i;
            fim = j;
        }

        int  maior = 0;
        for(int y = inicio; y <= fim; y++){
            int p = 0;
            int n = y;
            while(true){
                p++;
                if(n == 1) break;
                if(n % 2 == 0){
                    n = n / 2;
                }else{
                    n = 3 * n + 1;
                }
            }
            if (p > maior) maior = p;
        }
        cout << i << " " <<  j << " " << maior << endl;

    }


}