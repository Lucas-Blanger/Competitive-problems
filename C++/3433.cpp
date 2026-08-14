#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int j1, j2;
    cin >> j1 >> j2;

    int m1, m2;
    cin >> m1 >> m2;
    

    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    int cartas[13] = {1,2,3,4,5,6,7,8,9,10,10,10,10};
    map<int, int> baralho;
    baralho[1] = 4;
    baralho[2] = 4;
    baralho[3] = 4;
    baralho[4] = 4;
    baralho[5] = 4;
    baralho[6] = 4;
    baralho[7] = 4;
    baralho[8] = 4;
    baralho[9] = 4;
    baralho[10] = 4;
    baralho[11] = 4;
    baralho[12] = 4;
    baralho[13] = 4;
    baralho[j1]--;
    baralho[j2]--;
    baralho[m1]--;
    baralho[m2]--;


    int pontosJ = cartas[j1-1] + cartas[j2-1];
    int pontosM = cartas[m1-1] + cartas[m2-1];
    for(int i = 0; i < n;i++){
        pontosJ += cartas[p[i]-1];
        baralho[p[i]]--;
        pontosM += cartas[p[i]-1];
    }

    //cout << pontosJ << endl;
    //cout << pontosM << endl;

    int mariaW = 23 - pontosM;
    int joaoW = 24-pontosJ;
    
    int r = -1;
    for(int i = 1; i <= 13; i++) {
        if(baralho[i] >= 1) {
            int novoJ = pontosJ + cartas[i - 1];
            int novoM = pontosM + cartas[i - 1];

            if(novoM == 23 || (novoJ > 23 && novoM <= 23)) {
                r = i;
                break; 
            }
        }
    }
    cout << r << endl;

    //cout << " maria " <<mariaW << endl;
    //cout << " joao " <<joaoW << endl;


    //if(mariaW < joaoW) cout << mariaW << endl;
    //else if(mariaW > joaoW)cout << joaoW << endl;
    //else cout << -1 << endl;
}