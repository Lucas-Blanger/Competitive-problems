#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int x;
    double divisao,m,n;
    cin >> x;
    cout << fixed << setprecision(1);
    for(int i = 0; i < x;i++){
        cin >> m >> n;
        if(n == 0){
            cout << "divisao impossivel" << endl;
        } else {
           divisao = m / n;
           cout << divisao << endl;
        }
    }


}