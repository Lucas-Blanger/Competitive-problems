
#include <bits/stdc++.h>
using namespace std;

int comp[100005];  
const int N = 100005;
void dfs_componente(vector<vector<int>>& adj, vector<bool>& vis, int v, int id) {
    vis[v] = true;
    comp[v] = id;
    for (int viz : adj[v])
        if (!vis[viz])
            dfs_componente(adj, vis, viz, id);
}

int contarComponentes(vector<vector<int>>& adj) {
    int N = adj.size(), id = 0;
    vector<bool> vis(N, false);
    for (int i = 0; i < N; i++)
        if (!vis[i])
            dfs_componente(adj, vis, i, id++);
    return id; // número de componentes
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    unordered_map<string, int> pe;
    int y = 2;
    for (int i = 0; i < m; i++) {
        string n1, r, n2;
        cin >> n1 >> r >> n2;
        if(i == 0){
            pe[n1] = 0;
            pe[n2] = 1;
        }else{
            if(pe.count(n1) == false) {
               pe[n1] = y;
               y++;
            }
            if(pe.count(n2) == false) {
               pe[n2] = y;
               y++;
            }
        }
        
        int u, v;
        u =  pe[n1];
        v = pe[n2];
        //cout << u << " " << n1 << " " << v << " " << n2 << endl;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int r = contarComponentes(adj);

    cout <<  r << '\n';

}