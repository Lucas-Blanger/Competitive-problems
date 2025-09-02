#include <iostream>
#include <vector>

using namespace std;

int main(){
    int j, r;
    
    cin >> j >> r;
    int jogo[j*r];
    vector<int> pont(j, 0);

    for(int i = 0; i < j*r; i++){
        cin >> jogo[i];
    }

    for(int i = 0; i < j; i++){
        for(int y = i; y < j*r; y +=j ){
            pont[i] += jogo[y];
        }
    }

    int maior = 0;
    int pos = 0;

    for(int i = 0; i < j; i++){
        if(pont[i] >= maior) {
            maior = pont[i];
            pos = i + 1;
        }
    }

    cout << pos << endl;

}