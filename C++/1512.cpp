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


int mmc(int a, int b) {
    return (a / mdc(a, b)) * b; 
}

int mod(int a, int m) {
    return ((a % m) + m) % m;
}

int modexp(int a, int b, int n) {
    long long res;
    if(b == 0) return 1;
    res = modexp(a, b/2, n);
    res = (res * res) % n;
    if(b % 2 == 1) res = (res * a) % n;
    return (int)res;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        long long n,a,b;
        cin >> n >> a >> b;

        if(n == 0 && a == 0 && b ==0) break;


        long long r = 0;
        long long diva = n / a;           
        long long divb = n / b;           
        long long divmmc = n / mmc(a, b); 
        
        r = diva + divb - divmmc;

        cout << r << endl;

    

    }   
    
}