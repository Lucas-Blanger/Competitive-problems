#include <bits/stdc++.h>

using namespace std;

int main(){

    int v,n;
    cin >> v >> n;


    long long int cem = n*v;

    for(int i = 10; i <= 90; i+=10){
        long long int r = ceil((cem * i) / 100.0);
        if(i == 90){
            cout << r << endl;
        }else{
            cout << r << " ";
        }
        
    }


}