#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string dieta, cafe, almoco;
        getline(cin, dieta);
        getline(cin, cafe);
        getline(cin, almoco);

        bool pass = false;

        for(int j = 0; j < cafe.size(); j++){
            int pos = dieta.find(cafe[j]);
            if(pos != -1){
                dieta.erase(pos, 1);
            }else{
                pass = true;
                break;
            }
        }
        for(int j = 0; j < almoco.size(); j++){
            int pos = dieta.find(almoco[j]);
            if(pos != -1){
                dieta.erase(pos, 1);
            }else{
                pass = true;
                break;
            }
        }


        if(pass){
            cout << "CHEATER" << endl;
        }else{
            sort(dieta.begin(), dieta.end());
            cout << dieta << endl;
        }
    }
}