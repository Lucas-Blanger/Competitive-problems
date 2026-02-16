#include <bits/stdc++.h>

using namespace std;


int main(){
    vector<int> luck;
    for(int i = 0; i <= 1000;i++){
        string s;
        s = to_string(i);
        bool pass = true;
        for(int j = 0; j < s.size(); j++){
            if(s[j] != '4' && s[j] != '7') pass = false;
        }
        if(pass == true){
            luck.push_back(stoi(s));  
        } 
    }

    

   int n;
   cin >> n;
   bool pass = false;
   for(int i = 0; i < luck.size(); i++){
        if(n % luck[i] == 0) pass = true; 
        //cout << luck[i] << endl;
   }

   if(pass) cout << "YES" << endl;
   else cout << "NO" << endl;
 

}