#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main() {
    int n, k, m;
    while(cin >> n >> k >> m) {
        if(n == 0 && k == 0 && m == 0) break;

        deque<int> dq;
        for(int i = 1; i <= n; i++)
            dq.push_back(i);

        int h_start = 0;
        int a_start = n - 1;

        bool first = true;
        while(!dq.empty()) {
            int sz = dq.size();

            int h = (h_start + k - 1) % sz;
            int a = ((a_start - (m - 1)) % sz + sz) % sz;

            if(!first) cout << ",";
            first = false;

            if(h == a) {
                cout << setw(3) << dq[h];
                dq.erase(dq.begin() + h);
                if(!dq.empty()) {
                    sz = dq.size();
                    h_start = h % sz;
                    a_start = (h - 1 + sz) % sz;
                }
            } else {
                cout << setw(3) << dq[h] << setw(3) << dq[a];
                int lo = min(h, a), hi = max(h, a);
                dq.erase(dq.begin() + hi);
                dq.erase(dq.begin() + lo);
                if(!dq.empty()) {
                    sz = dq.size();
                    int next_h = h; if(h > lo) next_h--; if(next_h >= sz) next_h = 0;
                    h_start = next_h % sz;
                    int next_a = a; if(a > lo) next_a--;
                    next_a = (next_a - 1 + sz) % sz;
                    a_start = (next_a + sz) % sz;
                }
            }
        }
        cout << endl;
    }
}