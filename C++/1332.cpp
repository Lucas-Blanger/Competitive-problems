#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        string numb;
        cin >> numb;

        if(numb.size() == 3){
            int one = 0, two = 0;

            if(numb[0] == 'o') one++;
            if(numb[1] == 'n') one++;
            if(numb[2] == 'e') one++;

            if(numb[0] == 't') two++;
            if(numb[1] == 'w') two++;
            if(numb[2] == 'o') two++;

           

           if(one > two) cout << 1 << endl;
           else cout << 2 << endl;


            
        }else{
            cout << 3 << endl;
        }
    }
}
