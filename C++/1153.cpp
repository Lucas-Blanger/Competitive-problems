#include <iostream>
using namespace std;

int main(){
    int n, fat = 1;
    cin >> n;
    for(int i = n ; i >= 1; i--){
        fat = fat *  i; 
    }
    cout << fat << endl;
}
