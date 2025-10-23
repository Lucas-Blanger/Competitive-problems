#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int n;

    while(cin >> n){
        int y = 1;
        int espacos = (n/2);
        while(y <= n){

            for(int i = 0; i < espacos; i++){
                cout << ' ';
            }
            for(int i = 0; i < y; i++){
                cout << '*';
            }
            cout << endl;
            y+=2;
            espacos--;

        }

        for(int i = 0; i < ((n/2)); i++){
            cout << ' ';
        }
        cout << '*' << endl;

        for(int i = 0; i < ((n/2)-1); i++){
            cout << ' ';
        }
        cout << "***" << endl;
        cout << endl; 
   
    }
}
