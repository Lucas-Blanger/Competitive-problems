#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string frase;
        getline(cin, frase);

        vector<string> texto;

        stringstream ss(frase);
        string palavra;
        while(ss >> palavra){
            texto.push_back(palavra);
        }

        stable_sort(texto.begin(), texto.end(), [](const string &a, const string &b){
            return a.size() > b.size(); 
        }); 


        for(int i = 0; i < texto.size(); i++){
            if(i == (texto.size()-1)){
                cout << texto[i];
            }else{
                cout << texto[i] << " ";
            }
        }
        cout << endl;



    }
}