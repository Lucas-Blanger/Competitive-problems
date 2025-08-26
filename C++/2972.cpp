#include <iostream>

using namespace std;


long long countSetBits(long long n) {
    long long count = 0;
    while (n > 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main(){
    long long n;
    cin >> n;

    long long y = countSetBits(n);

    long long r = 1LL << y;

    cout << r << endl;
}