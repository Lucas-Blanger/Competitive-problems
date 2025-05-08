#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n, t, tempoTotal;
    string tempo;
    cin >> n;

    for(int i = 0; i <n;i++){
        cin >> t >> tempo;
        if(tempo == "1T" && t <= 45){
            cout << t << endl;
        } else if(tempo == "1T" && t > 45){
            tempoTotal = t - 45;
            cout << "45+" << tempoTotal << endl;
        }
        else if(tempo == "2T" && t <= 45){
            cout << t + 45 << endl;
        }else if(tempo == "2T" && t > 45){
            tempoTotal = t - 45;
            cout << "90+" << tempoTotal << endl;
        }



    }

}