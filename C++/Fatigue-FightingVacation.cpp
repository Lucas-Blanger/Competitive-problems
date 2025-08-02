#include <iostream>


using namespace std;

int main(){
    int d,c, r;

    cin >> d >> c >> r;
    int can[c];
    int re[r];
    int total = 0;

    for(int i = 0; i < c; i++){
        cin >> can[i];
    }

    for(int i = 0; i < r; i++){
        cin >> re[i];
        d += re[i];
        total++;
    }


    for(int i = 0; i < c; i++){
        if(can[i] <= d){
            total++;
            d -= can[i];
        }else{
            break;
        }
    }

    cout << total << endl;




}