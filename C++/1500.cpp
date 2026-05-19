#include <bits/stdc++.h>

using namespace std;

struct LazySegTree {
    int n;
    vector<long long> tree, lazy;

    LazySegTree(int n) : n(n), tree(4*n, 0), lazy(4*n, 0) {}

    void pushdown(int node, int l, int r) {
        if (lazy[node] == 0) return;
        int mid = (l + r) / 2;
        tree[2*node]   += lazy[node] * (mid - l + 1);
        lazy[2*node]   += lazy[node];
        tree[2*node+1] += lazy[node] * (r - mid);
        lazy[2*node+1] += lazy[node];
        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr, long long v) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            tree[node] += v * (r - l + 1);
            lazy[node] += v;
            return;
        }
        pushdown(node, l, r);
        int mid = (l + r) / 2;
        update(2*node,   l,   mid, ql, qr, v);
        update(2*node+1, mid+1, r, ql, qr, v);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        pushdown(node, l, r);
        int mid = (l + r) / 2;
        return query(2*node,   l,   mid, ql, qr)
             + query(2*node+1, mid+1, r, ql, qr);
    }

    void update(int l, int r, long long v) { update(1, 1, n, l, r, v); }
    long long query(int l, int r)          { return query(1, 1, n, l, r); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        LazySegTree seg(n);   

        for (int i = 0; i < c; i++) {
            int f;
            cin >> f;
            if (f == 0) {
                int p, q, v;
                cin >> p >> q >> v;
                seg.update(p, q, v);          // soma v em [p, q]
            } else {
                int p, q;
                cin >> p >> q;
                cout << seg.query(p, q) << "\n";  // soma de [p, q]
            }
        }
    }
}