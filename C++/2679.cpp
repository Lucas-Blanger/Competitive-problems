#include <iostream>


using namespace std;

int main(){
    int x;

    cin >> x;

    int y = x + 1;
    while(true){
        if(y % 2 == 0){
            cout << y << endl;
            break;
        }
        y++;
    

    }
}