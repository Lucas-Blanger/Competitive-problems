#include <bits/stdc++.h>

using namespace std;

int grid[1005][1005];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void floodFill(int sx, int sy, int n, int m) {
    queue<pair<int,int>> q;
    q.push({sx, sy});
    grid[sx][sy] = 0; 

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m
                && grid[nx][ny] == 1) {

                grid[nx][ny] = 0;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = (s[j] == '.'); 
        }
    }

    int r = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                floodFill(i, j, n, m);
                r++;
            }
        }
    }

    cout << r << "\n";
}