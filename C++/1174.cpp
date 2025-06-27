#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;


int main () {
    double N[100];

    for(int i = 0; i < 100; i++){
        cin >> N[i];
    }

    cout << fixed << setprecision(1);
    for(int i = 0; i < 100; i++){
        if(N[i] <= 10){
            cout << "A[" << i << "] = " << N[i] << endl;
        }
    }


}
    





