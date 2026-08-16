#include <bits/stdc++.h>


using namespace std;


int main(){
    string s;
    cin >> s;

    vector<int> aux(s.size(),0);

    for(int i = 0; i<s.size(); i++){
        if(i == 0) aux[i] = 1;
        else{
            if(s[i] == s[i-1]) {
                aux[i] += aux[i-1] + 1;
                aux[i-1] = 1;
            }
            else aux[i] = 1;
        }
    }

    string r = "";
    for(int i = s.size()-1; i>=0; i--){
        if(aux[i] > 1){
            string y = to_string(aux[i]);
            if(y.size() > 1) reverse(y.begin(), y.end());
            r += y; 
            r += s[i];
            i -= aux[i]-1;
        }else{
            r += s[i];
        }
       
    }
    reverse(r.begin(), r.end()); 
    cout << r << endl;

    

}