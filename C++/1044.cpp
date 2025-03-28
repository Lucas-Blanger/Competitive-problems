#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    if(b % a == 0 || a % b == 0){
        cout << "Sao Multiplos" << endl;
    } else {
        cout << "Nao sao Multiplos" << endl;
    }

}



