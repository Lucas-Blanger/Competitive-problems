#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int l=1,r=1;
    while(l != 0 && r != 0){
        cin >> l >> r;
        if(l == 0 && r ==0){
            break;
        }
        cout << l + r << endl;
    }
}