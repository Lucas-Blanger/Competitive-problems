#include <iostream>

using namespace std;

int main(){
    string n;
    cin >> n;
    int resto = 0;
    for (char c : n) {
        resto = (resto * 10 + (c - '0')) % 3;
    }

    if(resto == 1){
        cout << 1 << endl;
    } else if(resto == 2){
        cout << 2 << endl;
    }else{
        cout << 0 << endl;
    }
}