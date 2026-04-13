#include <bits/stdc++.h>


using namespace std;

const int INF = -1;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(vector<vector<int>>& grid) {
    vector<vector<int>> dist(5, vector<int>(5, INF));
    queue<pair<int,int>> fila;

    if (grid[0][0] == 1) return INF;

    dist[0][0] = 0;
    fila.push({0,0});

    while (!fila.empty()) {
        auto [x, y] = fila.front(); fila.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
                if (grid[nx][ny] == 0 && dist[nx][ny] == INF) {
                    dist[nx][ny] = dist[x][y] + 1;
                    fila.push({nx, ny});
                }
            }
        }
    }

    return dist[4][4];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        vector<vector<int>> grid(5, vector<int>(5));

        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                cin >> grid[i][j];
            }
        }
        int r = bfs(grid);

        if (r == INF) cout << "ROBBERS\n";
        else cout << "COPS\n";
    }
}