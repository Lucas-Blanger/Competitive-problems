#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;

string baixa(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

int main(){
    string ori, num, texto;
    while (getline(cin, ori) && getline(cin, num) && getline(cin, texto)) {
        string resultado = "";
        int i = 0;
        
        while (i < texto.size()) {
            if (texto[i] == '<') {
                int fim = i + 1;
                while (fim < texto.size() && texto[fim] != '>') {
                    fim++;
                }
                
                if (fim < texto.size()) {
                    string tag = texto.substr(i + 1, fim - i - 1);
                    string tagLower = baixa(tag);
                    string oriLower = baixa(ori);
                    

                    resultado += "<";
                    int pos = 0;
                    while (pos < tag.size()) {
                        int found = tagLower.find(oriLower, pos);
                        if (found != -1 && found >= pos) {
                            resultado += tag.substr(pos, found - pos);

                            resultado += num;
                            pos = found + ori.size();
                        } else {

                            resultado += tag.substr(pos);
                            break;
                        }
                    }
                    resultado += ">";
                    
                    i = fim + 1;
                } else {
                    resultado += texto[i];
                    i++;
                }
            } else {
                resultado += texto[i];
                i++;
            }
        }
        
        cout << resultado << endl;
    }
    

}