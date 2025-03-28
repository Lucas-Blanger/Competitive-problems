#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int hi, hf, cont1, cont2, total;
    cin >> hi >> hf;
 
    if(hi > hf){
        total = (24 - hi) + hf;
    } else if(hi == hf ){
        total = 24;
    } else if (hi < hf){
        total = (hi - hf) * -1;
    }

    cout << "O JOGO DUROU " << total << " HORA(S)" << endl;
    


}
