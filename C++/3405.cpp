#include <iostream>
using namespace std;

int contarZerosFatoriais(int N) {
    int zeros = 0;
    while (N >= 5) {
        zeros += N / 5;
        N /= 5;
    }
    return zeros;
}

int main() {
    int N;
    while (cin >> N) {
        cout << contarZerosFatoriais(N) << endl;
    }
    return 0;
}
