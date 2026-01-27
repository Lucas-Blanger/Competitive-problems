#include <bits/stdc++.h>


using namespace std;

int main(){
   while(true){
        int n;
        cin >> n;
        if(n == 0) break;

        int s = 0, p = 0;
        map<char, int> aux;
        while(n--){
            char probl;
            int t;
            string situ;
            cin >> probl >> t >> situ;

            if(situ == "correct"){
                s++;
                p += t + aux[probl];
            }else{
                aux[probl] += 20;
            }

        }
        cout << s << " " << p << endl;

   }
   

}