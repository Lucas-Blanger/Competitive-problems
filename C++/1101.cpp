#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int m=1, n=1, soma;
    cin >> m >> n;
    while(m > 0 && n > 0){
        soma = 0;
        if(n < m){
            swap(n,m);
        }
        for(int i = m; i <= n;i++){
            cout << i << " ";
            soma += i;
        }
        cout << "Sum=" << soma << endl;

        cin >> m >> n;
    }
}