#include <iostream>

using namespace std;

int main(){
    bool pode;
    int s[21];
    int B, N, dev, cre, v;

    while(cin >> B >> N){
        if(!B && !N)    break;

        for(int i = 1; i <= B; ++i){
            cin >> s[i];
        }

        for(int i = 0; i < N; ++i){
            cin >> dev >> cre >> v;

            s[dev] -= v;
            s[cre] += v;
        }

        pode = true;
        for(int i = 1; i <= B; ++i){
            if(s[i] < 0){
                pode = false;
                break;
            }
        }

        if(pode){
                cout << 'S'<< endl;
        }else {
            cout << 'N' << endl;
        }


    }


}