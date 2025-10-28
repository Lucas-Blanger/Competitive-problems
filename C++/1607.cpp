#include <bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        string a, b;
        cin >> a >> b;

        int t = 0;

        int j = a.size() - 1;
        while(a != b){
            if(a[j] == b[j]){
                j--;
                if(j < 0) break; 
            } else {
                t++;
                if(int(a[j]) + 1 > 122){
                    a[j] = char(97);
                } else {
                    a[j] = char(int(a[j]) + 1);
                }
            }
        }
        cout << t << endl;
    
    }
}