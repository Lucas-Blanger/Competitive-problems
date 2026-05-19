#include <bits/stdc++.h>
using namespace std;

int bit[1005][1005];
int W, H;

void update(int x, int y, int v) {
    for (int i = x; i <= W; i += i & -i)
        for (int j = y; j <= H; j += j & -j)
            bit[i][j] += v;
}

int query(int x, int y) {
    int s = 0;
    for (int i = x; i > 0; i -= i & -i)
        for (int j = y; j > 0; j -= j & -j)
            s += bit[i][j];
    return s;
}

int query(int x1, int y1, int x2, int y2) {
    return query(x2, y2)
         - query(x1-1, y2)
         - query(x2, y1-1)
         + query(x1-1, y1-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, Y, P;
    while (cin >> X >> Y >> P && (X || Y || P)) {
        W = X; H = Y;
        memset(bit, 0, sizeof(bit));

        int Q;
        cin >> Q;
        while (Q--) {
            char type;
            cin >> type;

            if (type == 'A') {
                int n, x, y;
                cin >> n >> x >> y;
                update(x + 1, y + 1, n);

            } else { 
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                if (x1 > x2) swap(x1, x2);
                if (y1 > y2) swap(y1, y2);
                long long total = (long long)query(x1+1, y1+1, x2+1, y2+1) * P;
                cout << total << "\n";
            }
        }
        cout << "\n";
    }

}