#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int x, y, impares = 0;
    cin >> x >> y;

    if (x > y) {
        swap(x, y);
    }

    for (int i = x + 1; i < y; i++) {
        if (i % 2 != 0) {
            impares += i;
        }
    }

    cout << impares << endl;

}