#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;

        vector<string> alunos(k);

        for(int j = 0; j < k; j++){
            cin >> alunos[j];
        }

        vector<pair<string, int>> idioma;


        for(int j = 0; j < k; j++){
            bool p = false;

            for(int y = 0; y < idioma.size(); y++){
                if(idioma[y].first == alunos[j]){
                    idioma[y].second++;
                    p = true;
                    break;
                }
            }
            if(p == false){
                idioma.push_back(make_pair(alunos[j], 1));
            }
        }


        if(idioma.size() == 1){
            cout << idioma[0].first << endl;
        }   else{
            cout << "ingles" << endl;
        }

        



    

    }
    
}