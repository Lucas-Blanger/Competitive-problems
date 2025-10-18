#include <bits/stdc++.h>

using namespace std;


int main(){
  int n,s;
  cin >> n >> s;
  int menor = INT_MAX;

  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    s += x;
    if(s < menor) menor = s;
  }

  cout << menor << endl;
  
}