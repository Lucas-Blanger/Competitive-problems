#include <iostream>


using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int aprovados[n];
    for(int i = 0; i < n; i++){
        cin >> aprovados[i];
    }
    int total = 0;
    for(int i = 0; i < n; i++){
        if(aprovados[i] >= aprovados[k-1] && aprovados[k-1] > 0){
            total++;
        }
    }

    cout << total << endl;



}