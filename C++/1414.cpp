#include <bits/stdc++.h>

using namespace std;

int main(){

    int t,n;
    while(true){
        cin >> t >> n;

        if(t == 0 && n == 0){
            break;
        }

        int total =0;
        string time;
        vector<int> times(t);
        for(int i = 0; i < t; i++){
            cin >> time >> times[i];
        }

        int aux = 0;
        for(int i = 0; i < t; i++){

            aux += times[i];
         
        }

        total = 3 * n - aux;

        cout << total << endl;


     
    }

}