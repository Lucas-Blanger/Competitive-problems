#include <iostream>

using namespace std;

int main(){
    bool passou = true;
    for(int i = 0; i < 8; i++){
        int a;
        cin >> a;
        if(a == 9){
            passou = false;
        }
    }

    if(passou){
        cout << "S" << endl;
    }else{
        cout << "F" << endl;
    }
}