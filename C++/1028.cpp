#include <bits/stdc++.h>


using namespace std;

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}



int main(){
    int n;
    cin >> n;


    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        cout << mdc(a,b) << endl;
    }
}