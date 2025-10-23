#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;

        string turma[n];
        string freq[n];

        for(int j = 0; j < n; j++){
            cin >> turma[j];
        }
        for(int j = 0; j < n; j++){
            cin >> freq[j];
        }
        vector<string> ausentes;
        bool pass = false;

        for(int j = 0; j < n; j++){
            int total = 0;
            double p =0, a = 0, m = 0;
            string aux = freq[j];
            for(int y = 0; y < aux.size(); y++){
                if(aux[y] == 'P'){
                    p++;
                    total++;
                }else if(aux[y] == 'A'){
                    a++;
                    total++;
                }else if(aux[y] == 'M'){
                    m++;
                }
            }
            double freq = (100*p) / total;
            if(freq < 75.0){
                ausentes.push_back(turma[j]);
                pass = true;
            }
        }

        if(pass == false){
            cout << endl;
        }else{
            for(int j = 0; j < ausentes.size(); j++){
                if(j != ausentes.size()-1){
                    cout << ausentes[j] << " ";
                }else{
                    cout << ausentes[j] << endl;
                }
            }

        }
        
        


       
    }
}
