#include <iostream>

using namespace std;

int main(){
    int t, d, m;
    cin >> t >> d >> m;

    int ref[m];
    for(int i = 0; i < m; i++){
        cin >> ref[i];
    }

    bool dormiu = false;
    
    int neg = 0; 
    for(int i = 0; i < m + 1; i++){
        if(i == m){
            int num = d - neg;
            if(num >= t){
                dormiu = true;
                break;
            }
            break;
        }
        int num = ref[i] - neg;
        if(num >= t){
            dormiu = true;
            break;
        }
        neg = ref[i];
    }
    if(m == 0){
        dormiu = (d >= t); 
    }
    if(dormiu){
        cout << "Y" << endl;
    }else{
        cout << "N" << endl;
    }
}
