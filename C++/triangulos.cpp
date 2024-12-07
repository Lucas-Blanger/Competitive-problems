#include <iostream>
#include <vector>
using namespace std;

    int vet[1000002];


int main(){

    int n, a;
    cin >> n;
    int last = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        vet[i] = min(a, last + 1);
        last = vet[i];

    }
    last = 0;
    int m = 0;
    for(int i = n-1; i >= 0; i--){

        vet[i] = min(vet[i], last + 1);
        last = vet[i];
        m = max(m, vet[i]);

    }

    cout << m << endl;

}