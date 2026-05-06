#include <bits/stdc++.h>



using namespace std;

struct DSU {
    vector<int> pai, rank_;
 
    DSU(int n) : pai(n), rank_(n, 0) {
        iota(pai.begin(), pai.end(), 0);
    }
 
    int find(int x) {
        if (pai[x] != x) pai[x] = find(pai[x]);
        return pai[x];
    }
 
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rank_[a] < rank_[b]) swap(a, b);
        pai[b] = a;
        if (rank_[a] == rank_[b]) rank_[a]++;
        return true;
    }
};

long long kruskal(int n, vector<tuple<int,int,int>> edges) {
    sort(edges.begin(), edges.end());
 
    DSU dsu(n);
    long long custo = 0;
    int arestas = 0;
 
    for (auto& [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            custo += w;
            if (++arestas == n - 1) break;
        }
    }
 
    return (arestas == n - 1) ? custo : -1;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m,n;
    while(true){
        cin >> m >> n;
        if(m == 0 && n == 0) break;

        vector<tuple<int,int,int>> edges; // {peso, u, v}

        for(int i = 0; i < n; i++){
            int x,y,z;
            cin >> x >> y >> z;
            edges.push_back({z,x,y});
        }


        long long resultado = kruskal(m, edges);
        cout << resultado << "\n";
    }
    
 


}