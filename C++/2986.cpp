#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int maneiras(int n) {
    vector<int> resposta(n + 1);
    resposta[0] = 1;
    if (n >= 1) resposta[1] = 1;
    if (n >= 2) resposta[2] = 2;

    for (int i = 3; i <= n; i++) {
        resposta[i] = (((resposta[i - 1] + resposta[i - 2]) % MOD + resposta[i - 3]) % MOD) % MOD;
    }

    return resposta[n];
}

int main() {
    int n;
    cin >> n;
    cout << maneiras(n) << endl;
    return 0;
}
