#include <bits/stdc++.h>


using namespace std;

int tabu[9][9];

int main() {

    int n;
    cin >> n;
    int insta = 0;
    while(n--){
        insta++;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cin >> tabu[i][j];
            }
        }

        bool pass = true;

        for (int i = 0; i < 9 && pass; i++) {
            bool visto[10] = {false};

            for (int j = 0; j < 9; j++) {
                int num = tabu[i][j];

                if (num < 1 || num > 9 || visto[num]) {
                    pass = false;
                    break;
                }

                visto[num] = true;
            }
        }

        for (int j = 0; j < 9 && pass; j++) {

            bool visto[10] = {false};

            for (int i = 0; i < 9; i++) {
                int num = tabu[i][j];

                if (num < 1 || num > 9 || visto[num]) {
                    pass = false;
                    break;
                }

                visto[num] = true;
            }
        }

        for (int bloco_i = 0; bloco_i < 3 && pass; bloco_i++) {
            for (int bloco_j = 0; bloco_j < 3 && pass; bloco_j++) {

                bool visto[10] = {false};

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {

                        int num = tabu[bloco_i*3 + i][bloco_j*3 + j];

                        if (num < 1 || num > 9 || visto[num]) {
                            pass = false;
                            break;
                        }

                        visto[num] = true;
                    }
                }
            }
        }
        cout << "Instancia " << insta << endl;
        if (pass) cout << "SIM\n\n";
        else cout << "NAO\n\n";



    }



   

}


