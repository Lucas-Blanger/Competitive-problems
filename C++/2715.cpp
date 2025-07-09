#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<long long int> somas;

    while (cin >> n){
        somas.assign(n, 0);

        cin >> somas[0];

        for (int i = 1; i < n; i++){
            cin >> somas[i];
            somas[i] += somas[i - 1];
        }

        int inicio = 0, fim = n;
        long long int r = somas[n - 1];

        while (inicio < fim){
            int meio = (inicio + fim) / 2;

            long long int rangel = somas[meio];
            long long int gu = somas[n - 1] - rangel;

            r = min(r, abs(rangel - gu));

            if (rangel == gu){
                break;
            } else if (rangel < gu){
                inicio = meio + 1;
            }else{
                fim = meio;
            }
        }

        cout << r << endl;
    }

}