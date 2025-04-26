#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int i=1, j=60;

    cout << "I=" << i << " J=" << j << endl;
    while (j!=0){
        j -= 5;
        i += 3;

        cout << "I=" << i << " J=" << j << endl;
    }

}