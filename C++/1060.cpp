#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int pos = 0;
    double x;
    for(int i = 0; i <= 5; i++){
        cin >> x;
        if(x >= 0){
            pos++;
        }
    }
    cout << pos << " valores positivos" << endl;

}