#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <cmath>

using namespace std;

int main(){
    int x, a, b;
    int wa, wb;
    while (true){
        x = 0;
        a = 0;
        b = 0;
        wa = 0;
        wb = 0;

        cin >> x;
        if(x == 0){
            break;
        }
        for(int i = 0; i < x; i++){
            cin >> a >> b;
            if(a > b){
                wa++;
            } else if(b > a){
                wb++;
            } else {
                continue;
            }
        }
         cout << wa << " " << wb <<  endl;
    }
    
    
}