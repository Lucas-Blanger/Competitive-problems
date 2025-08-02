#include <iostream>


using namespace std;

int main(){

    int n, h;

    cin >> n >> h;

    int br = 0;

    for(int i = 0; i < n; i++){
        int aa;
        cin >> aa;
        if(aa <= h){
            br++;
        }   
    }

    cout << br << endl;

}