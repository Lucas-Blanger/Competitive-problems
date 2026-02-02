#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 13;
const int MAX_K = 7;
int C[MAX_N][MAX_K];
void precompute() {
    C[0][0] = 1;
    for(int i = 1; i < MAX_N; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= i && j < MAX_K; j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}


// Gerar k-ésima combinação diretamente O(k)
vector<int> kthCombinationVector(const vector<int>& S, int k, long long idx) {
    int n = S.size();
    vector<int> result;
    int start = 0;

    for (int i = 0; i < k; i++) {
        for (int j = start; j < n; j++) {
            long long cnt = C[n - j - 1][k - i - 1];
            if (idx < cnt) {
                result.push_back(S[j]);
                start = j + 1;
                break;
            }
            idx -= cnt;
        }
    }
    return result;
}


int main(){
    precompute();

    bool first = true;
    while(true){
        int k;
        cin >> k;
        if(k == 0) break;
        if(!first) cout << endl;

        vector<int> aux;
        for(int i = 0; i < k; i++){
            int y;
            cin >> y;
            aux.push_back(y);
        }
        int permuta = C[k][6];
        

        for(int i = 0; i < permuta; i++){
            vector<int> r = kthCombinationVector(aux, 6, i);
            for(int j = 0; j < 6; j++){
                if(j != 5) cout << r[j] << " ";
                else cout << r[j] << endl;
            }
        }
        first = false;

    }
}