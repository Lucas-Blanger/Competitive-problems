#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int i = 1; 
    for(int count = 0; count < n; count++){
        cout << i << " " << i + 1 << " " << i + 2 << " PUM" << endl;
        i += 4; 
    }

}
