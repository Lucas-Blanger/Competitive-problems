#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;

    while(cin >> n){
        // largada e chegada
       unordered_map<int, int> grid;
       vector<int> largada;
       vector<int> chegada;


       for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        largada.push_back(x);
       
       }
       for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        chegada.push_back(x);
       }

        for(int i = 0; i < n; i++){
            grid[largada[i]] = i;
        }
        
        int r = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(grid[chegada[i]] > grid[chegada[j]]){
                    r++;
                }
            }
        }
        
        cout << r << endl;
       
      
            
    }

    


}