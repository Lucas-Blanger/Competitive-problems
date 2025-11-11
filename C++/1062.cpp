#include <bits/stdc++.h>


using namespace std;


int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        while(true){
            stack<int> esta;
            vector<int> ordem;
          
            int x;
            for(int i = 0; i < n; i++){
                cin >> x;
                if(x == 0) break;
                ordem.push_back(x);
            }
            if(x == 0) break;

            bool pass = true;
            int next = 1;
            for(int i = 0; i < n; i++){
                int aux = ordem[i];

                while(next <= n && (esta.empty() || esta.top() != aux)){
                    esta.push(next);
                    next++;
                }

                if(!esta.empty() && esta.top() == aux){
                    esta.pop();
                } else {
                    pass = false;
                    break;
                }


            }

            if(pass) cout << "Yes" << endl;
            else cout << "No" << endl;

            
            


        }
        cout << endl;

        
    }
}