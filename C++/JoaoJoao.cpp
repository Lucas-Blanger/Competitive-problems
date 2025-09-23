#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> aux(4,0);

    for(int i = 0; i < 10; i++){
        int a;
        cin >> a;
        if (a == 1){
            aux[0] = 1;
        }else if(a == 2){
            aux[1] = 1;
        }else if(a == 3){
            aux[2] = 1;
        }else if(a == 4){
            aux[3] = 4;
        }
    }

    int r = 0;
    for(int i = 0; i < 4;i++){
        if(aux[i] == 0){
            r++;
        }
    }

    cout << r << endl;




}