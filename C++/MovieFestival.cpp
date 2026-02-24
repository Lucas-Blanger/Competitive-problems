#include <bits/stdc++.h>

using namespace std;

struct Atividade {
    int inicio, fim;
};

int intervalScheduling(vector<Atividade>& ativ) {
    sort(ativ.begin(), ativ.end(), 
         [](auto& a, auto& b) { return a.fim < b.fim; });
    
    int count = 0, ultimo = -1;
    for (auto& a : ativ) {
        if (a.inicio >= ultimo) {
            count++;
            ultimo = a.fim;
        }
    }
    return count;
}



int main() {

    int n;
    cin >> n;
    vector<Atividade> atividades(n);
    for(int i = 0; i < n; i++){
        cin >> atividades[i].inicio >> atividades[i].fim;
    }

    int r = intervalScheduling(atividades);
    cout << r << endl;

}
