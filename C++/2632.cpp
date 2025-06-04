#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int w, h, x0, y0;
        cin >> w >> h >> x0 >> y0;
        string m;
        int l, cx, cy;
        cin >> m >> l >> cx >> cy;

        int r = 0, d = 0;
        if (m == "fire") {
            d = 200;
            if (l == 1) r = 20;
            else if (l == 2) r = 30;
            else r = 50;
        } else if (m == "water") {
            d = 300;
            if (l == 1) r = 10;
            else if (l == 2) r = 25;
            else r = 40;
        } else if (m == "earth") {
            d = 400;
            if (l == 1) r = 25;
            else if (l == 2) r = 55;
            else r = 70;
        } else if (m == "air") {
            d = 100;
            if (l == 1) r = 18;
            else if (l == 2) r = 38;
            else r = 60;
        }

        int x1 = x0 + w;
        int y1 = y0 + h;

        int px = max(x0, min(cx, x1));
        int py = max(y0, min(cy, y1));

        int dx = px - cx;
        int dy = py - cy;

        int dist2 = dx * dx + dy * dy;

        if (dist2 <= r * r) cout << d << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}
