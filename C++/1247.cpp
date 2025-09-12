#include <bits/stdc++.h>

using namespace std;

int main(){
    int d, vf, vg;

    while(cin >> d >> vf >> vg){

        double distguar = sqrt(pow(12,2) + pow(d, 2));
        
        double tGC = distguar / vg;
        double tFC = 12.0 / vf;

        if(tGC <= tFC){
            cout << "S" << endl;
        }else {
            cout << "N" << endl;
        }
    }
}