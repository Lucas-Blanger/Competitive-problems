#include <bits/stdc++.h>

using namespace std;


int main(){
    while(true){
        int a,b;
        cin >> a >> b;

        if(a == 0 && b == 0) break;

        set<int> beatriz;
        set<int> alice;
        int r = 0;
        for(int i = 0; i < a; i++){
            int x;
            cin >> x;
            alice.insert(x);
        }
        for(int i = 0; i < b; i++){
            int x;
            cin >> x;
            
            beatriz.insert(x);
        }
        set<int> resultado;

        int t;

       
        if(alice.size() > beatriz.size()){
            for(auto x:beatriz){
                if(alice.find(x) == alice.end()){
                    r++;
                }
            }
        }else{
            for(auto x:alice){
                if(beatriz.find(x) == beatriz.end()){
                    r++;
                }
            
            }
        }

        cout << r << endl;
     


    
    }
}
    