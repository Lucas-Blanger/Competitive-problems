#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <cmath>

using namespace std;

int main(){
   int a, b, c, m;
   cin >> a >> b >> c;
   b = (a+b+abs(a-b)) / 2;
   m = b = (b+c+abs(b-c)) / 2;
   cout << m << " eh o maior" << endl;
}