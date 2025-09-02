#include <bits/stdc++.h>
using namespace std;

int H, L;
int mat[205][205], area_id[205][205];
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

struct Area {
    int cor, tam;
};

vector<Area> areas;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> L;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < L; j++) {
            cin >> mat[i][j];
        }
    }

    memset(area_id, -1, sizeof(area_id));
    int id = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < L; j++) {
            if (mat[i][j] != 0 && area_id[i][j] == -1) {
                int cor = mat[i][j], tam = 0;
                queue<pair<int, int>> q;
                q.push({ i, j });
                area_id[i][j] = id;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    tam++;

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (nx >= 0 && nx < H && ny >= 0 && ny < L) {
                            if (mat[nx][ny] == cor && area_id[nx][ny] == -1) {
                                area_id[nx][ny] = id;
                                q.push({ nx, ny });
                            }
                        }
                    }
                }

                areas.push_back({ cor, tam });
                id++;
            }
        }
    }

    unordered_map<int, int> min_area;
    for (auto &a : areas) {
        if (!min_area.count(a.cor)) {
            min_area[a.cor] = a.tam;
        } else {
            min_area[a.cor] = min(min_area[a.cor], a.tam);
        }
    }

    int ans = INT_MAX;
    for (auto &kv : min_area) {
        ans = min(ans, kv.second);
    }

    vector<vector<int>> vis(H, vector<int>(L, 0));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < L; j++) {
            if (mat[i][j] == 0 && !vis[i][j]) {
                vector<pair<int, int>> comp;
                queue<pair<int, int>> q;
                q.push({ i, j });
                vis[i][j] = 1;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    comp.push_back({ x, y });

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (nx >= 0 && nx < H && ny >= 0 && ny < L) {
                            if (mat[nx][ny] == 0 && !vis[nx][ny]) {
                                vis[nx][ny] = 1;
                                q.push({ nx, ny });
                            }
                        }
                    }
                }

                int compSize = comp.size();
                unordered_map<int, int> soma;

                for (auto [x, y] : comp) {
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (nx >= 0 && nx < H && ny >= 0 && ny < L) {
                            if (mat[nx][ny] != 0) {
                                int aid = area_id[nx][ny];
                                int c = areas[aid].cor;
                                soma[c] += areas[aid].tam;
                            }
                        }
                    }
                }

                for (auto &kv : soma) {
                    int c = kv.first;
                    int novo = compSize + kv.second;
                    if (!min_area.count(c)) {
                        min_area[c] = novo;
                    } else {
                        min_area[c] = min(min_area[c], novo);
                    }
                }

                ans = min(ans, compSize);
            }
        }
    }

    cout << ans << "\n";
}
