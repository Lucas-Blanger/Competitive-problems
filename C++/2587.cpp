#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        string p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        
        vector<char> r1;
        for(int j = 0; j < p3.size(); j++){
            if(p3[j] == '_'){
                r1.push_back(p1[j]);
            }
        }
        
        vector<char> r2;
        for(int j = 0; j < p3.size(); j++){
            if(p3[j] == '_'){
                r2.push_back(p2[j]);
            }
        }
        
        bool r = false;
        for(int j = 0; j < r1.size(); j++){
            bool pass = false;
            for(int k = 0; k < r2.size(); k++){
                if(r2[k] == r1[j]){
                    pass = true;
                    break;
                }
            }
            
            if(r1[j] != r2[j] && pass){
                r = true;
                break;
            }
        }
        
        if(r) cout << "Y" <<  endl;
        else cout << "N" << endl;
    }
    
}