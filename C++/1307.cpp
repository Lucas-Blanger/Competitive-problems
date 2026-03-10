#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}




int main() {
    int n;
    cin >> n;
    int pair = 0;

    while(n--){
        string s1, s2;
        cin >> s1 >> s2;
        pair++;
        int auxS1 = strtol(s1.c_str(),NULL,2);
        int auxS2 = strtol(s2.c_str(),NULL,2);

        int pass = gcd(auxS1, auxS2);
        if(pass != 1) cout << "Pair #" << pair << ": " << "All you need is love!" << endl;
        else cout << "Pair #" << pair << ": " <<  "Love is not all you need!" << endl;


    }
    
    
}