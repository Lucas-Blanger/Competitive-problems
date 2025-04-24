#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int x;
    cin >> x;

    int i = 1;
    while(i <= 6){
    if(x % 2 == 1){
        cout << x << endl;
        i++;
    }
    x++;

    }
}