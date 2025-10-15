#include <bits/stdc++.h>

using namespace std;


int main(){
    int  total = 0;
    vector<int> v(4);

   

    for(int i = 0; i < 4; i++){
        cin >> v[i];
    }

    for(int i = 0; i < 4; i++){
        if(i == 3){
            total += v[i];
        }else{
            total += v[i] -1;
        }
    }

    cout << total << endl;
    
}