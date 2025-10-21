#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;


int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string linha;
        cin >> linha;
        int num1, num2, num3;
        num1 = stoi(linha.substr(2,2));
        num2 = stoi(linha.substr(5,3));
        num3 = stoi(linha.substr(11));

        cout << num1 + num2 + num3 << endl;
    
    }
}