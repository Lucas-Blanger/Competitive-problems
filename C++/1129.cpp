#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;


int main() {
    int n,a,b,c,d,e, aux;
    string m;
    while(true){
        cin >> n;
        if(n == 0){
            break;
        }
        for(int i =0;i< n;i++){
            aux = 0;
            cin >> a >> b >> c >> d >> e;
            if(a <= 127){
                m = "A";
                aux++;
            }   
            if(b <= 127){
                m = "B";
                aux++;
            }
            if(c <= 127){
                m = "C";
                aux++;
            }
            if(d <= 127){
                m = "D";
                aux++;
            }
            if(e <= 127){
                m = "E";
                aux++;
            }
            if(aux == 0 || aux > 1){
                cout << "*" << endl;
            } else {
                cout << m << endl;
            }

        }
    }
   
}

