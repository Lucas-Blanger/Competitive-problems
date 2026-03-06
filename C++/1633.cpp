#include <bits/stdc++.h>
using namespace std;

struct Processo {
    int tempo, Nciclos;
};

bool ordena(Processo a, Processo b){
    return a.tempo < b.tempo;
}

struct cmp {
    bool operator()(Processo a, Processo b){
        return a.Nciclos > b.Nciclos;
    }
};

int main() {

    int n;

    while(cin >> n){

        vector<Processo> sist(n);

        for(int i = 0; i < n; i++){
            cin >> sist[i].tempo >> sist[i].Nciclos;
        }

        sort(sist.begin(), sist.end(), ordena);

        priority_queue<Processo, vector<Processo>, cmp> fila;

        long long tempoAtuc = 0;
        long long r = 0;

        int i = 0;

        while(i < n || !fila.empty()){

            if(fila.empty() && i < n)
                tempoAtuc = max(tempoAtuc, (long long)sist[i].tempo);

            while(i < n && sist[i].tempo <= tempoAtuc){
                fila.push(sist[i]);
                i++;
            }

            Processo p = fila.top();
            fila.pop();

            r += tempoAtuc - p.tempo;

            tempoAtuc += p.Nciclos;
        }

        cout << r << endl;
    }
}