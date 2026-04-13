#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
//Kahn (BFS)
vector<int> toposort(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for (int u = 0; u < n; u++)
        for (int v : adj[u]) indegree[v]++;

   
    // Kahn com ordem lexicográfica mínima — só muda queue → priority_queue
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0) pq.push(i);

    vector<int> order;
    while (!pq.empty()) {
        
        int u = pq.top(); pq.pop(); 
        order.push_back(u);
        for (int v : adj[u])
            if (--indegree[v] == 0) pq.push(v);
    }
    // se order.size() != n → tem ciclo!
    return order;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }

    vector<int> order = toposort(n, adj);

    if ((int)order.size() != n) {
        cout << "Sandro fails.\n";
        return 0;
    }

    for (int x : order)
        cout << x + 1 << " ";
    cout << "\n";
}