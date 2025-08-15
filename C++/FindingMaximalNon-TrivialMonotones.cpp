#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    string m;
    cin >> m;

    int r = 0;
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(m[i+1] == 'a' && m[i] == 'a'){
                r+=1;
                continue;
            }
        }
        if(i == n-1){
            if(m[i-1] == 'a' && m[i] == 'a'){
                r+=1;
                continue;
            }
        }
        if(m[i] == 'a' && (m[i+1] == 'a' ||m [i-1] == 'a')){
            r+=1;
            continue;
        }
    }

    cout << r << endl;
}