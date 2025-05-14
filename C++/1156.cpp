#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double total = 1.0;
    cout << fixed << setprecision(2);

    for(double i = 3, den = 2; i <= 39; i += 2, den *= 2){
        total += i / den;
    }

    cout << total << endl;
}
