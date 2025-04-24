#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int pares = 0;
    int x;
    for(int i = 0; i <= 4; i++){
        cin >> x;
        if(x % 2 == 0){
            pares++;
        }
    }


    cout << pares << " valores pares" << endl;

}