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

    int n, m;
    cin >> n >> m;
   
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int v,u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    vector<vector<int>> componentes;
    int total = contarComponentes(adj, componentes);
    cout << total-1 << endl;


}