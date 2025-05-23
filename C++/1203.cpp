#include <iostream>
#include <cstring>

using namespace std;

int R, K;
int graus[101];
int resposta[101][4951];

int DP(int regiao, int pontes){
    if(regiao > R)  return 0;

    if(resposta[regiao][pontes] == -1){
        if(pontes == K){
            resposta[regiao][pontes] = 1;
        }else if(pontes > K){
            resposta[regiao][pontes] = 0;
        }else{
            resposta[regiao][pontes] = DP(regiao + 1, pontes) ||
                                       DP(regiao + 1, pontes + graus[regiao]);
        }
    }

    return resposta[regiao][pontes];
}

int main(){
    int A, B;

    while(cin >> R >> K){
        memset(graus, 0, sizeof(graus));
        memset(resposta, -1, sizeof(resposta));

        for(int i = 0; i < K; ++i){
            cin >> A >> B;
            ++graus[A];
            ++graus[B];
        }

        cout << (char) (DP(1, 0) ? 'S' : 'N') << endl;
    }

    return 0;
}