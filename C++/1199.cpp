#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> 

using namespace std;


int main(){
    while(true){
        string n;
        cin >> n;

        if(n[0] == '-'){
            break;
        }
        string nova = "";
        if(n.size() > 1 && tolower(n[1]) == 'x'){
            for(int i = 2; i < n.size(); i++){
                nova += n[i];
            }
            long final = strtol(nova.c_str(),NULL,16);
            cout << dec << final << endl; 
        }else{
            int num = stoi(n);
            cout << "0x" << uppercase << hex << num << nouppercase << dec << '\n';
        }

    }

}