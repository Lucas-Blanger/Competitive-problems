#include <bits/stdc++.h>


using namespace std;

int main(){
    int n;
    while(true){
        cin >> n;
        if(n == 0) break;
        string co;
        cin >> co;
        char s = 'N';

        for(int i = 0; i < co.size(); i++){
            if(co[i] == 'D'){
                if(s == 'N'){
                    s = 'L';
                }else if(s == 'L'){
                    s = 'S';
                }else if(s == 'S'){
                    s = 'O';
                }else{ // s == O
                    s = 'N';
                }
            }else{
                if(s == 'N'){
                    s = 'O';
                }else if(s == 'L'){
                    s = 'N';
                }else if(s == 'S'){
                    s = 'L';
                }else{ // s == O
                    s = 'S';
                }
            }
        }
        cout << s << endl;

    }
    

}