#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pol(n+1,0);

    for(int i = n; i >= 0; i--){
        cin >> pol[i];
    }


    int cont = 0;
    while(pol.size() != 1){
        cont++;
        if(pol[0] == 1){
            pol.push_back(1);
           for(int i = pol.size()-2; i > 0; i--){
            pol[i] = pol[i] + pol[i-1];
            if(pol[i] == 2) pol[i] = 0;
            
           }
           pol[0] = 0;
        }else{
            for(int i = 0; i <  pol.size(); i++){
                if(i == pol.size()-1){
                    break;

                }else if(pol[i+1] == 1){
                    pol[i] = 1;
                    pol[i+1] = 0;
                }
            }
            pol.pop_back();
         
        }
       


        


    }
    cout << cont << endl;
   
    
}