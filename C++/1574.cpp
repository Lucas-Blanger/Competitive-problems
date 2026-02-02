#include <bits/stdc++.h>

using namespace std;



int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int p = 0;
        vector<string> struc;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            if(s == "SAME"){
                string two;
                cin >> two;
                int pos;
                cin >> pos;
                if(struc[pos-1] == "LEFT"){
                    p--;
                    struc.push_back("LEFT");
                }else{
                    struc.push_back("RIGHT");
                    p++;
                }
            }else if(s == "LEFT"){
                struc.push_back("LEFT");
                p--;
            }else{
                struc.push_back("RIGHT");
                p++;
            }
        }
        cout << p << endl;
    }
    
}