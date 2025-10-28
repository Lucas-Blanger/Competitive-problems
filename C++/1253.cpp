#include <iostream>
#include <string>

using namespace std;


int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string cifra;
        cin >> cifra;
        int t;
        cin >> t;

        string nova = "";

        for(int j = 0; j < cifra.size(); j++){
            if(int(cifra[j]) - t < 65){
                int di = ((int(cifra[j] - 65) - t) + 90) +1;
                nova += char(di);
            }else{
                nova += char(int(cifra[j]) - t);
   
            }

        }
        cout << nova << endl;
    }
}