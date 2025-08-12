#include <iostream>


using namespace std;

int main(){
    int d, c ,r;
    cin >> d >> c >> r;

    int rev[r];
    int can[c];
    for(int i = 0; i < c; i++){
        cin >> can[i];
    }
    int quant = 0;

    for(int i = 0; i < r; i++){
        cin >> rev[i];
        d += rev[i];
        quant++;
    }

    for(int i = 0; i < c; i++){
        if(d >= can[i]){
            quant++;
            d -= can[i];
        } else {
            break;
        }
    }

    cout << quant << endl;

   



}