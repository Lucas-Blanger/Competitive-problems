#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int pos, maior =0;

    for(int i = 0; i < 100; i++){
        int n;
        cin >> n;
        if(n > maior){
            maior = n;
            pos = i+1;
        }
    }
    cout << maior << endl;
    cout << pos << endl;

}