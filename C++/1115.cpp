#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){

    int x=1, y=1;
    cin >> x >> y;
    while(x != 0 && y != 0){
    
        if(x > 0 && y > 0){
            cout << "primeiro" << endl;
        } else if(x < 0 && y > 0){
            cout << "segundo" << endl;
        } else if(x < 0 && y < 0){
            cout << "terceiro" << endl;
        } else if(x > 0 && y < 0){
            cout << "quarto" << endl;
        }

        cin >> x >> y;
    }


}