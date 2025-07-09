#include <iostream>

using namespace std;

int main(){
    int n;
    string palavra;

    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> palavra;

        if(i)   cout << ' ';
        if(palavra.length() == 3){
            if(palavra[0] == 'O' && palavra[1] == 'B')
                cout << "OBI";
            else if(palavra[0] == 'U' && palavra[1] == 'R')
                cout << "URI";
            else{
                cout << palavra;
            }
        }else{
            cout << palavra;
        }
    }
    cout << endl;

}