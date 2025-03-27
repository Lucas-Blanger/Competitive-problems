#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int cod, quant;
    cin >> cod >> quant;

    cout << fixed << setprecision(2);
    if(cod == 1){
        cout << "Total: R$ " << quant * 4.00 << endl;
    } else if(cod == 2){
        cout << "Total: R$ " << quant * 4.50 << endl;
    } else if(cod == 3){
        cout << "Total: R$ " << quant * 5.00 << endl;
    } else if(cod == 4){
        cout << "Total: R$ " << quant * 2.00 << endl;
    } else if(cod == 5){
        cout << "Total: R$ " << quant * 1.50 << endl;
    }

}



