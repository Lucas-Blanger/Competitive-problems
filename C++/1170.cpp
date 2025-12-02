#include<bits/stdc++.h>


using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        double num;
        cin >> num;
        int cont = 0;

        while(num > 1.0){
            cont++;
            num = num - (num*0.5);
        }
        cout << cont <<  " dias" << endl;
    }

  
}