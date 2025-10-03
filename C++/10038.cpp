#include <bits/stdc++.h>


using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        bool pass = true;
        vector<int> v2;

        for(int i = 0; i < n-1; i++){
            v2.push_back(abs(v[i+1] - v[i]));
        }

        sort(v2.begin(), v2.end());

        for(int i = 1; i < n; i++){
            if(find(v2.begin(), v2.end(), i) == v2.end()) pass = false;

        }


        if(pass){
            cout << "Jolly" << endl;
        }else{
            cout << "Not jolly" << endl;
        }
    }
}