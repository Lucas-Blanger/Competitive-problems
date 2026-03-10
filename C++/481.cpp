#include <bits/stdc++.h>

using namespace std;

vector<int> LIS(vector<int>& a) {
    int n = a.size();

    vector<int> tails;
    vector<int> parent(n, -1);
    vector<int> pos;

    for (int i = 0; i < n; i++) {

        auto it = lower_bound(tails.begin(), tails.end(), a[i]);
        int p = it - tails.begin();

        if (it == tails.end()) {
            tails.push_back(a[i]);
            pos.push_back(i);
        } else {
            *it = a[i];
            pos[p] = i;
        }

        if (p > 0)
            parent[i] = pos[p - 1];
    }

    vector<int> lis;
    int k = pos.back();

    while (k != -1) {
        lis.push_back(a[k]);
        k = parent[k];
    }

    reverse(lis.begin(), lis.end());

    return lis;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   
    vector<int> seq;
    int n;
    while(cin >> n){
        seq.push_back(n);
    }

    vector<int> r = LIS(seq);

    cout << r.size() << endl;
    cout << "-" << endl;

    for(int i = 0; i < r.size(); i++){
        cout << r[i] << endl;
    }




   

  
}