#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string maior;
    int mai = 0;

    while (true){
        
        string frase;
        getline(cin, frase);
        if(frase == "0") break;

        string r = "";
        string delta = "";

        for(int i = 0; i < frase.size(); i++){
            if(frase[i] != ' '){
                delta += frase[i];
            }else{
                string aux = delta;
                int t = aux.size();
                if(t >= mai){
                    maior = aux;
                    mai = t;
                }
                r += to_string(t) + '-';
                delta = "";
                
            }
        }
        if(delta != ""){
            string aux = delta;
            int t = aux.size();
            if(t >= mai){
                maior = aux;
                mai = t;
            }
            r += to_string(t) + '-';
            delta = "";

        }

        r.pop_back();
        cout << r << endl;

    }
    cout << endl;
    cout << "The biggest word: " << maior << endl;
    
   
}