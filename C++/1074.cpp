#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,x;
    string txt = "";
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        if(x == 0){
            cout << "NULL" << endl;
        }
        if(x < 0 && x % 2 == 0){
            cout << "EVEN NEGATIVE" << endl;
        }
        if(x < 0 && x % 2 != 0){
            cout << "ODD NEGATIVE" << endl;
        }
        if(x > 0 && x % 2 == 0){
            cout << "EVEN POSITIVE" << endl;
        }
        if(x > 0 && x % 2 != 0){
            cout << "ODD POSITIVE" << endl;
        }
     
     

    }

}