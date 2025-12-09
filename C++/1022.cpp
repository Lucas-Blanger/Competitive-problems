#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        long long n1, d1, n2, d2;
        char s1, s2, op;

        cin >> n1 >> s1 >> d1 >> op >> n2 >> s2 >> d2;

        long long nr, dr;

        if (op == '+') {
            nr = n1 * d2 + n2 * d1;
            dr = d1 * d2;
        } 
        else if (op == '-') {
            nr = n1 * d2 - n2 * d1;
            dr = d1 * d2;
        } 
        else if (op == '*') {
            nr = n1 * n2;
            dr = d1 * d2;
        } 
        else { 
            nr = n1 * d2;
            dr = d1 * n2; 
        }

        long long a = nr, b = dr;
        if (a < 0) a = -a;
        if (b < 0) b = -b;

        while (b != 0) {
            long long r = a % b;
            a = b;
            b = r;
        }

        long long mdc = a;

        long long sn = nr / mdc;
        long long sd = dr / mdc;

        if (sd < 0) { sd = -sd; sn = -sn; } 

        cout << nr << "/" << dr << " = " << sn << "/" << sd << "\n";
    }

}
