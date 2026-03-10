#include <bits/stdc++.h>

using namespace std;

int LIS(vector<int> &a) {
    vector<int> tails;

    for (int x : a) {
        auto it = lower_bound(tails.begin(), tails.end(), x);

        if (it == tails.end())
            tails.push_back(x);
        else
            *it = x;
    }

    return tails.size(); 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vet(n);

    for(int i = 0; i < n; i++){
        cin >> vet[i];
    }

    cout << LIS(vet) << endl;

  
}