#include <iostream>

using namespace std;

int main(){
    int a1,a2,a3;

    cin >> a1 >> a2 >> a3;

    int total = 0, total2 = 0, total3 = 0;;

    total = (a2 * 2) + (a3 * 4);
    total2 = (a1 * 2) + (a3 * 2);
    total3 = (a2 * 2) + (a1 * 4);
    
    if(total <= total2 && total <= total3){
        cout << total << endl;
    } else if(total2 <= total && total2 <= total3){
        cout  << total2 << endl;
    }else {
        cout <<total3 << endl;
    }





}