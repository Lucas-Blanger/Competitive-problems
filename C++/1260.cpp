#include <bits/stdc++.h>


using namespace std;


int main(){
    int n;
    cin >> n;

    cin.ignore();
    cin.ignore();
    for(int i = 0; i < n; i++){
        string linha;
        map<string, int> mata;
        map<string, int>::iterator it;
        int total = 0;

        while (true){
            getline(cin,linha);
            if(linha == ""){
                for(it = mata.begin(); it != mata.end(); it++){
                    double fraq = ((it->second) * 100.0) / total;
                    cout << fixed << setprecision(4);
                    cout << it->first << " " << fraq << endl;
                }
                if(i != n-1) cout << endl;
                break;
            }else{
                mata[linha]++;
                total++;
            }
        }
        

    }
}