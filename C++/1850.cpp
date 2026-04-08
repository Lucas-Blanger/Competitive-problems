#include <bits/stdc++.h>
using namespace std;


struct State {
    int r, c, mask;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    vector<string> grid;
    while (getline(cin, line)) {
        if (!line.empty()) grid.push_back(line);
    }

    if (grid.empty()) { cout << "--\n"; return 0; }

    int R = grid.size();
    int C = grid[0].size();

    int sr = -1, sc = -1; 
    int er = -1, ec = -1; 

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < (int)grid[r].size(); c++) {
            if (grid[r][c] == '@') { sr = r; sc = c; }
            if (grid[r][c] == '*') { er = r; ec = c; }
        }
    }


    const int MASKS = 128; // 2^7
    vector<vector<vector<int>>> dist(R, vector<vector<int>>(C, vector<int>(MASKS, -1)));

    queue<State> fila;
    dist[sr][sc][0] = 0;
    fila.push({sr, sc, 0});

    const int dr[] = {-1, 1, 0, 0};
    const int dc[] = {0, 0, -1, 1};

    while (!fila.empty()) {
        auto [r, c, mask] = fila.front();
        fila.pop();

        int cur_dist = dist[r][c][mask];

        if (r == er && c == ec) {
            cout << cur_dist << "\n";
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

            char cell = grid[nr][nc];

            if (cell == '#') continue;

            if (cell >= 'A' && cell <= 'G') {
                int bit = cell - 'A';
                if (!(mask & (1 << bit))) continue; 
            }

            int new_mask = mask;
            if (cell >= 'a' && cell <= 'g') {
                int bit = cell - 'a';
                new_mask |= (1 << bit);
            }

            if (dist[nr][nc][new_mask] == -1) {
                dist[nr][nc][new_mask] = cur_dist + 1;
                fila.push({nr, nc, new_mask});
            }
        }
    }

    cout << "--\n";

}