#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int n,f;
    string nome;
    cin >> n;
    for(int i =0; i < n;i++){
        cin >> nome >> f;
        if(nome == "Thor"){
            cout << "Y" << endl;
        } else{
            cout << "N" << endl;
        }
    }
}