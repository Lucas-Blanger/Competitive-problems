#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int x=1, y=2;
   
    while(x != y){
        cin >> x >> y;
        if(x > y){
            cout << "Decrescente" << endl;
        } else if(x < y) {
            cout << "Crescente" << endl;
        } else {
            break;
        }
    }

}