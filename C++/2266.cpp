#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C;
    if (!(cin >> N >> C)) return 0;

    vector<long long> E(N + 1, 0);
    for (int i = 1; i <= N; ++i) cin >> E[i];

    vector<vector<pair<int,int>>> adj(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int A, B, W;
        cin >> A >> B >> W;
        adj[A].push_back({B, W});
        adj[B].push_back({A, W});
    }

    vector<int> parent(N + 1, 0);
    vector<int> order; order.reserve(N);
    vector<int> w_to_parent(N + 1, 0); 

    stack<int> st;
    st.push(1);
    parent[1] = -1;

    while (!st.empty()) {
        int u = st.top(); st.pop();
        order.push_back(u);
        for (auto [v, w] : adj[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            w_to_parent[v] = w;
            st.push(v);
        }
    }

    vector<long long> subsum = E;
    long long ans = 0;

    for (int i = (int)order.size() - 1; i >= 0; --i) {
        int u = order[i];
        for (auto [v, w] : adj[u]) {
            if (parent[v] == u) {
                subsum[u] += subsum[v];
                long long trips = (subsum[v] + C - 1) / C;   
                ans += 2LL * w_to_parent[v] * trips;         
            }
        }
    }

    cout << ans << "\n";

}