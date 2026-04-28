#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int INF = 1e9;

vector<pii> adj[505];
vector<int> g[505], gr[505];
int comp[505], vis[505];
stack<int> st;

void dfs1(int u){
    vis[u] = 1;
    for(auto [v,_] : adj[u]){
        if(!vis[v]) dfs1(v);
    }
    st.push(u);
}

void dfs2(int u, int c){
    comp[u] = c;
    for(int v : gr[u]){
        if(comp[v] == -1) dfs2(v,c);
    }
}

int main(){
    int n,m;
    while(cin >> n >> m && (n||m)){
        
        for(int i=1;i<=n;i++){
            adj[i].clear();
            g[i].clear();
            gr[i].clear();
        }

        for(int i=0;i<m;i++){
            int u,v,w;
            cin >> u >> v >> w;
            adj[u].push_back({v,w});
            g[u].push_back(v);
            gr[v].push_back(u);
        }

        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            if(!vis[i]) dfs1(i);
        }

        memset(comp,-1,sizeof(comp));
        int c = 0;
        while(!st.empty()){
            int u = st.top(); st.pop();
            if(comp[u]==-1) dfs2(u,c++);
        }

        int k; cin >> k;
        while(k--){
            int o,d; cin >> o >> d;

            vector<int> dist(n+1, INF);
            priority_queue<pii, vector<pii>, greater<pii>> pq;

            dist[o]=0;
            pq.push({0,o});

            while(!pq.empty()){
                auto [cd,u]=pq.top(); pq.pop();
                if(cd>dist[u]) continue;

                for(auto [v,w]: adj[u]){
                    int cost = (comp[u]==comp[v]) ? 0 : w;

                    if(dist[u]+cost < dist[v]){
                        dist[v]=dist[u]+cost;
                        pq.push({dist[v],v});
                    }
                }
            }

            if(dist[d]==INF) cout<<"Nao e possivel entregar a carta\n";
            else cout<<dist[d]<<"\n";
        }

        cout<<"\n";
    }
}