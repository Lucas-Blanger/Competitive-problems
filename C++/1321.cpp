#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        vector<int> vet(55, 0);
        vector<int> prin(3, 0);
        vector<int> rei(2, 0);

        cin >> prin[0] >> prin[1] >> prin[2] >> rei[0] >> rei[1];

        if (prin[0] == 0 && prin[1] == 0 && prin[2] == 0 && rei[0] == 0 && rei[1] == 0) break;

        vet[prin[0]] = -1;
        vet[prin[1]] = -1;
        vet[prin[2]] = -1;
        vet[rei[0]] = -1;
        vet[rei[1]] = -1;

        sort(prin.begin(), prin.end()); 
        sort(rei.begin(), rei.end());  

        int r = -1;

    
        if (rei[0] > prin[2]) {
            int carta = 1;
            while (carta <= 52 && vet[carta] == -1) carta++;
            
            if (carta <= 52) r = carta;
        }else if (rei[0] > prin[1]) {
            int carta = prin[1] + 1;
            while (carta <= 52 && vet[carta] == -1)carta++;
            
            if (carta <= 52) r = carta;
        }else if (rei[1] > prin[2]) {
            int carta = prin[2] + 1;
            while (carta <= 52 && vet[carta] == -1) {
                carta++;
            }
            if (carta <= 52) r = carta;
        }else r = -1;
        

        cout << r << "\n";
    }


}