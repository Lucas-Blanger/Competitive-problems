#include <bits/stdc++.h>

using namespace std;


int main(){
   int nc;
   cin >> nc;

   for(int i = 0; i < nc; i++){
    int n;
    cin >> n;

    vector<int> p(n);

    for(int j = 0; j < n;j++){
        cin >> p[j];
    }
    sort(p.begin(), p.end());

    for(int j = 0; j < n;j++){
        if(j == n-1){
            cout << p[j] << endl;
        }else{
            cout << p[j] << " ";
        }
    }
   }
}