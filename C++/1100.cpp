#include <bits/stdc++.h>
using namespace std;

const int INF = -1;

vector<int> bfs(vector<vector<int>>& adj, int start) {
    int N = adj.size();
    vector<int> dist(N, INF);
    queue<int> fila;

    dist[start] = 0;
    fila.push(start);

    while (!fila.empty()) {
        int v = fila.front(); fila.pop();

        for (int viz : adj[v]) {
            if (dist[viz] == INF) {
                dist[viz] = dist[v] + 1;
                fila.push(viz);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int dx[] = {-2,-2,-1,-1,1,1,2,2};
    int dy[] = {-1,1,-2,2,-2,2,-1,1};

    vector<vector<int>> adj(64);

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            int u = x * 8 + y;

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                    int v = nx * 8 + ny;
                    adj[u].push_back(v);
                }
            }
        }
    }

    string a, b;

    while (cin >> a >> b) {
        int x1 = a[0] - 'a';
        int y1 = a[1] - '1';

        int x2 = b[0] - 'a';
        int y2 = b[1] - '1';

        int start = x1 * 8 + y1;
        int end   = x2 * 8 + y2;

        vector<int> dist = bfs(adj, start);

        cout << "To get from " << a << " to " << b
             << " takes " << dist[end] << " knight moves.\n";
    }
}