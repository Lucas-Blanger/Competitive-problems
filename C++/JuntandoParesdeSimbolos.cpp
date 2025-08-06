#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_map<char, long long> freq;
    for (char c : s) {
        freq[c]++;
    }

    long long total = 0;
    for (auto par : freq) {
        total += par.second * par.second;
    }

    cout << total << endl;

}