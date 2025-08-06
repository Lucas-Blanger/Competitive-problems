#include <bits/stdc++.h>

using namespace std;

int main(){
    int x;
    cin >> x;
    
    int passos = 0;
    while(x != 0){
        if((x - 5) >= 3 || x-5 == 0){
            x -= 5;
            passos++;
            continue;
        }
        if((x - 4) >= 3 || x-4 == 0){
            x -= 4;
            passos++;
            continue;
        }
        if(x-3 >= 3 || x-3 == 0){
            x -= 3;
            passos++;
            continue;
        }
        if(x-2 >= 2 || x-2 == 0){
            x -= 2;
            passos++;
            continue;
        }
        if(x-1 >= 1 || x-1 == 0){
            x -= 1;
            passos++;
            continue;
        }
    }
    cout << passos << endl;
}