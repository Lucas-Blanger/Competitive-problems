#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> leds;
    leds[0] = 6;
    leds[1] = 2;
    leds[2] = 5;
    leds[3] = 5;
    leds[4] = 4;
    leds[5] = 5;
    leds[6] = 6;
    leds[7] = 3;
    leds[8] = 7;
    leds[9] = 6;

    int n;
    cin >> n;


    for(int i = 0; i < n; i++){
        string num;
        cin >> num;
        int r = 0;
        for(int j = 0; j < num.size(); j++){
            r += leds[num[j] -'0'];

        }
        cout << r << " leds" <<endl;
        
    }


   
}
