#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> 

using namespace std;

void binParaDec(string bin){
    cout << strtol(bin.c_str(), NULL, 2) << " dec" << endl;
}

void binParaHex(string bin){
    int num =  strtol(bin.c_str(),NULL,2);
    cout << hex << num << dec << " hex"  << endl;
}

void decParaHex(string deci){
    int num = stoi(deci);
    cout << hex << num << dec << " hex"  << endl;
    
}

string decParaBin(string deci){
    int num = stoi(deci);
    string bin = "";
    int velho;
    while(num / 2 >= 1){
        velho = num;
        num = num / 2;
        if(num == 1){
            bin += to_string(velho % 2);
            bin += "1";
            break;
        }
        bin += to_string(velho % 2);
    }
    string nova;
    for(int i = bin.size() - 1; i >=0; i--){
        nova += bin[i];
    }
    return nova;

}

void hexParaDec(string hexa){
  cout << strtol(hexa.c_str(), NULL, 16) << " dec" << endl;
}

void hexParaBin(string hexa){
    int num =  strtol(hexa.c_str(),NULL,16);
    string deci = to_string(num);
    string bin = decParaBin(deci);   
    
    cout << bin << " bin" << endl;

}





int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string y, x;
        cin >> x >> y;

        if(y == "bin"){
            cout << "Case " << i + 1 << ":" << endl;
            binParaDec(x);
            binParaHex(x);
            cout << endl;
            continue;
        }
        if(y == "dec"){
            cout << "Case " << i + 1 << ":" << endl;
            decParaHex(x);
            string bin = decParaBin(x);
            cout << bin << " bin" << endl;
            cout << endl;
            continue;
        }
        if(y == "hex"){
            cout << "Case " << i + 1 << ":" << endl;
            hexParaDec(x);
            hexParaBin(x);
            cout << endl;
            continue;
        }

        cout << endl;
    }
    

}