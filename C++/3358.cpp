#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string sob;
        cin >> sob;

        vector<int> val(sob.size());
        
        for(int i = 0; i < sob.size(); i++){
            if(i == 0){
                if(tolower(sob[i]) != 'a' && tolower(sob[i]) != 'e' && tolower(sob[i]) != 'i' && tolower(sob[i]) != 'o' && tolower(sob[i]) != 'u'){
                    val[i] = 1;
                }else{
                    val[i] = 0;
                }
            }else{
                if(tolower(sob[i]) != 'a' && tolower(sob[i]) != 'e' && tolower(sob[i]) != 'i' && tolower(sob[i]) != 'o' && tolower(sob[i]) != 'u'){
                    val[i] = val[i-1]+1;
                }else{
                    val[i] = 0;
                }

            }
        }
        bool r = false;
        for(int i = 0; i < sob.size(); i++){
            if(val[i] >= 3) r = true; 
        }

        if(r) cout << sob << " nao eh facil" << endl;
        else cout << sob << " eh facil" << endl;
    }


}