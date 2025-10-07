#include <bits/stdc++.h>

using namespace std;

int main(){
   int n;
   cin >> n;

   int p, b;

   if(n % 2 != 0){
        p = (n*n) / 2;
        b = ((n*n) / 2) + 1;

   }else{
        p = (n* n) /2;
        b = (n* n) /2;
   }

   cout << b << " casas brancas e " << p << " casas pretas" << endl;
}