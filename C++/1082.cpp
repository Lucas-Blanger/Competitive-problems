#include <bits/stdc++.h>
using namespace std;

int comp[100005];   // comp[v] = id do componente de v

void dfs_componente(vector<vector<int>>& adj, vector<bool>& vis, int v, int id, vector<int>& componente) {
    vis[v] = true;
    comp[v] = id;
    componente.push_back(v);
    for (int viz : adj[v])
        if (!vis[viz])
            dfs_componente(adj, vis, viz, id, componente);
}

int contarComponentes(vector<vector<int>>& adj, vector<vector<int>>& componentes) {
    int N = adj.size(), id = 0;
    vector<bool> vis(N, false);
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            vector<int> componente;
            dfs_componente(adj, vis, i, id++, componente);
            sort(componente.begin(), componente.end());
            componentes.push_back(componente);
        }
    }
    return id;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int caso = 0;
   int n;
   cin >> n;
   while(n--){
    caso++;
    int v,e;
    cin >> v >> e;

    vector<vector<int>> adj(v);

    for(int i = 0; i < e;i++){
        char U,V;
        cin >> U >> V;
        int a = U - 'a';
        int b = V - 'a';
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<int>> componentes;
    int total = contarComponentes(adj, componentes);

    cout << "Case #" << caso << ':' << endl;
    for (auto& c : componentes) {
            for (int ver : c)
                cout << (char)('a' + ver) << ",";
            cout << "\n";
        }
        cout << total << " connected components\n";
        cout << "\n";
   }
}