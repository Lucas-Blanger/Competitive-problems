#include <bits/stdc++.h>


using namespace std;

int main(){
   int t;
   cin >> t;

   for(int i = 0; i < t; i++){
        int m, n;
        cin >> m >> n;
        map<string, string> dic;
        for(int j = 0; j < m; j++){
            string br, jap;
            cin >> jap;
            cin.ignore();
            getline(cin, br);
            dic[jap] = br;
        
        }
        for(int j = 0; j < n; j++){
            string br;
            getline(cin, br);

            stringstream ss(br);
            string palavra;
            int aux = 0;
            while (ss >> palavra){
                
                if(aux != 0) cout << " ";
                if(dic.find(palavra) == dic.end()) cout << palavra;
                else cout << dic[palavra];
            
                aux++;
            }
            cout << endl;
            
        }
        cout << endl;
   }




}